#pragma once

#include<utility>
#include<string>
#include<cstdlib>
#include<time.h>
#include <random>
#include <iostream>
#include <fstream>
#include <sstream> 

#include "const.h"
#include "MatrixException.h"
#include "FileError.h"

namespace MyAlgebra
{
	template <typename T>
	class CMatrix
	{
	private:
		T** rowPtr;

		int     rowCount;
		int     columnCount;

		// return:	true if memory allocation for matrix successful
		//			false otherwise
		// warning: method do not check if memory is already allocated
		bool allocateMemory(int rowCnt, int colCnt);

		void deallocateMemory();

		void populateMatrixWithRandomNumbers();

		void copyMatrixValues(const CMatrix& other);

		void copyOperation(const CMatrix& other);

		void moveOperation(CMatrix&& other);

		void diagonalOperation(T diagonal);

		CMatrix<T> multiplyConstantOperation(T multiplier)const;

		CMatrix<T> multiplyMatrixOperation(const CMatrix<T>& other) const;

		CMatrix<T> addMatrixOperation(const CMatrix<T>& other)const;

		CMatrix<T> substractMatrixOperation(const CMatrix<T>& other)const;

		CMatrix<T> unaryOperation()const;

		CMatrix<T> transponseOperation() const;

		CMatrix<T> powerOperation(int power) const;

		CMatrix<T> dotProductOperation(const CMatrix<T>& other) const;

		bool comparisionOperation(const CMatrix<T>& other) const;

		CMatrix(T** newRowPtr, int rowCnt, int colCnt);

	public:
		static const float ALG_PRECISION;

		// =========================================================================
		// constructors:
		// =========================================================================

		// create matrix with (possible) random values
		CMatrix(int rowCnt, int colCnt, bool randInit);

		// create square diagonal matrix
		CMatrix(int rowCnt, T diagonal);

		CMatrix(const CMatrix& other);

		CMatrix(CMatrix&& other) noexcept;

		~CMatrix();

		inline CMatrix createMatrix(int rowCnt, int colCnt, bool randInit = false) { return std::move(CMatrix(rowCnt, colCnt, randInit)); }

		// =========================================================================
		// assign operators:
		// =========================================================================

		const CMatrix& operator=(const CMatrix& other);
		const CMatrix& assignMatrix(const CMatrix& other);

		// move operator
		const CMatrix& operator=(CMatrix&& other)noexcept;
		const CMatrix& moveMatrix(CMatrix&& other);

		// switch matrix to diagonal matrix 
		const CMatrix& operator=(T diagonal);
		const CMatrix& toDiagonal(T diagonal);

		// =========================================================================
		// indexing matrix
		// =========================================================================

		inline T* operator[](int row_ind) { return rowPtr[row_ind]; }
		inline T* getRow(int row_ind) { return rowPtr[row_ind]; }

		void set(int rowIndex, int columnIndex, T newVal);

		T get(int rowIndex, int columnIndex);

		inline int getRowCount() const { return rowCount; }
		inline int getColumnCount() const { return columnCount; }

		inline std::pair<int, int> getDims() const { return std::pair<int, int>(rowCount, columnCount); }

		inline bool isInitialized() const { return !(rowPtr == nullptr && rowCount <= 0 && columnCount <= 0); }

		inline bool isInitialized(const CMatrix& other) const { return !(other.rowPtr == nullptr && other.rowCount <= 0 && other.columnCount <= 0); }

		inline bool equalDimensions() const { return rowCount == columnCount; }

		inline bool equalDimensions(const CMatrix& other) const { return rowCount == other.rowCount && columnCount == other.columnCount; }

		inline bool canMultiply(const CMatrix& other) const { return columnCount == other.rowCount; }

		// =========================================================================
		// return vector matrix from rows/columns
		// =========================================================================

		CMatrix getRowVector(int rowIndex);

		CMatrix getColumnVector(int columnIndex);

		// =========================================================================
		// algebraic operations
		// =========================================================================

		inline CMatrix operator*(const CMatrix& other) const { return std::move(this->multiplyMatrixOperation(other)); }
		inline CMatrix multiply(const CMatrix& other) const { return std::move(this->multiplyMatrixOperation(other)); }

		// multiply matrix by constant
		inline CMatrix operator*(T multiplier) const { return std::move(this->multiplyConstantOperation(multiplier)); }
		inline CMatrix multiply(T multiplier) const { return std::move(this->multiplyConstantOperation(multiplier)); }

		inline CMatrix operator+(const CMatrix& other) const { return std::move(this->addMatrixOperation(other)); }
		inline CMatrix add(const CMatrix& other) const { return std::move(this->addMatrixOperation(other)); }

		inline CMatrix operator-(const CMatrix& other) const { return std::move(this->substractMatrixOperation(other)); }
		inline CMatrix substract(const CMatrix& other) const { return std::move(this->substractMatrixOperation(other)); }

		// change sign of all elements of matrix
		inline CMatrix operator-() const { return std::move(this->unaryOperation()); }
		inline CMatrix unary() const { return std::move(this->unaryOperation()); }

		// transponse matrix
		inline CMatrix operator~() const { return std::move(this->transponseOperation()); }
		inline CMatrix transponse() const { return std::move(this->transponseOperation()); }

		// accept only power >= 0:
		//    power = 0  - return unity matrix
		//    power = 1  - return copy of matrix
		//    power > 1  - return power of matrix
		inline CMatrix operator^(int power) const { return std::move(this->powerOperation(power)); }
		inline CMatrix power(int power) const { return std::move(this->powerOperation(power)); }

		// dot product (iloczyn skalarny) A^T*B
		inline CMatrix dotProduct(const CMatrix& other) const { return std::move(this->dotProductOperation(other)); }

		// compare matrix with accuracy to ALG_PRECISION
		inline bool operator==(const CMatrix& rhs) const { return comparisionOperation(rhs); }
		inline bool compareTo(const CMatrix& rhs) const { return comparisionOperation(rhs); }

		// =========================================================================
		// I/O operations
		// =========================================================================

		FileError readMatrixFromFile(std::string fileName);

		// only for tests - display matrix by rows on stdout
		void display() const;

		friend CMatrix operator*(T multiplier, const CMatrix& other) { return std::move(other.multiplyConstantOperation(multiplier)); }
	};

	template <typename T>
	const float MyAlgebra::CMatrix<T>::ALG_PRECISION = 1e-6f;

	// =========================================================================
	// methods declarations
	// =========================================================================

	template <typename T>
	bool CMatrix<T>::allocateMemory(int rowCnt, int colCnt) {
		if (rowCnt <= 0 || colCnt <= 0) {
			rowPtr = nullptr;
			return false;
		}

		rowPtr = new(std::nothrow) T * [rowCnt];

		if (rowPtr != nullptr) {
			for (int i = 0; i < rowCnt; i++) {
				rowPtr[i] = new(std::nothrow) T[colCnt];

				if (rowPtr[i] == nullptr) {
					for (; i > 0; i--) {
						delete[] rowPtr[i];
					}
					delete[] rowPtr;
					rowPtr = nullptr;
					this->rowCount = 0;
					this->columnCount = 0;
					return false;
				}
			}
		}
		this->rowCount = rowCnt;
		this->columnCount = colCnt;
		return true;
	}

	template <typename T>
	void CMatrix<T>::deallocateMemory() {
		for (int i = 0; i < rowCount; i++) {
			delete[] rowPtr[i];
		}
		delete[] rowPtr;
		rowPtr = nullptr;
		rowCount = 0;
		columnCount = 0;
	}

	template <typename T>
	void CMatrix<T>::copyMatrixValues(const CMatrix<T>& other) {
		for (int i = 0, j = 0; i < other.columnCount; i++) {
			for (j = 0; j < other.columnCount; j++) {
				this->rowPtr[i][j] = other.rowPtr[i][j];
			}
		}
	}

	template <typename T>
	void CMatrix<T>::copyOperation(const CMatrix& other) {
		if (allocateMemory(other.rowCount, other.columnCount)) {
			copyMatrixValues(other);
		}
	}

	template <typename T>
	void CMatrix<T>::moveOperation(CMatrix&& other) {

		this->rowPtr = other.rowPtr;
		this->rowCount = other.rowCount;
		this->columnCount = other.columnCount;

		other.rowPtr = nullptr;
		other.rowCount = 0;
		other.columnCount = 0;

	}

	template <typename T>
	void CMatrix<T>::diagonalOperation(T diagonal) {

		if (!isInitialized()) {
			throw MatrixNotInitialized(OP_DIAGONAL);
		}
		if (!(rowCount == columnCount)) {
			throw NotSquareMatrix(OP_DIAGONAL, getDims());
		}

		for (int i = 0, j = 0; i < rowCount; i++) {
			for (j = 0; j < columnCount; j++) {
				if (i == j) {
					rowPtr[i][j] = diagonal;
				}
				else {
					rowPtr[i][j] = 0;
				}
			}
		}
	}

	template <typename T>
	CMatrix<T> CMatrix<T>::multiplyConstantOperation(T multiplier) const {

		CMatrix<T> retMatrix(*this);

		if (!isInitialized(retMatrix)) {
			throw MatrixNotInitialized(OP_MULTIPLY_CONST);
		}

		for (int i = 0, j; i < rowCount; i++) {
			for (j = 0; j < columnCount; j++) {
				retMatrix.rowPtr[i][j] *= multiplier;
			}
		}
		return std::move(retMatrix);
	}

	template <typename T>
	CMatrix<T> CMatrix<T>::multiplyMatrixOperation(const CMatrix<T>& other) const {

		if (!canMultiply(other)) {
			throw DimensionMismatchException(OP_MULTIPLY_MATRIX, getDims(), other.getDims());
		}

		CMatrix<T> retMatrix(this->rowCount, other.columnCount, false);

		if (!retMatrix.isInitialized()) {
			throw MatrixNotInitialized(OP_MULTIPLY_MATRIX);
		}

		T fieldSum;
		for (int i = 0, j, r; i < retMatrix.getRowCount(); i++) {
			for (j = 0; j < retMatrix.getColumnCount(); j++) {
				for (r = 0, fieldSum = 0; r < this->columnCount; r++) {
					fieldSum += +rowPtr[i][r] * other.rowPtr[r][j];
				}
				retMatrix[i][j] = fieldSum;
			}
		}

		return std::move(retMatrix);
	}

	template <typename T>
	CMatrix<T> CMatrix<T>::addMatrixOperation(const CMatrix<T>& other) const {

		if (!equalDimensions(other)) {
			throw DimensionMismatchException(OP_ADD, getDims(), other.getDims());
		}

		CMatrix<T> retMatrix(*this);

		if (!isInitialized(retMatrix)) {
			throw MatrixNotInitialized(OP_ADD);
		}

		for (int i = 0, j; i < rowCount; i++) {
			for (j = 0; j < columnCount; j++) {
				retMatrix.rowPtr[i][j] += other.rowPtr[i][j];
			}
		}
		return std::move(retMatrix);
	}

	template <typename T>
	CMatrix<T> CMatrix<T>::substractMatrixOperation(const CMatrix<T>& other) const {

		if (!equalDimensions(other)) {
			throw DimensionMismatchException(OP_SUBSTRACT, getDims(), other.getDims());
		}

		CMatrix<T> retMatrix(*this);

		if (!isInitialized(retMatrix)) {
			throw MatrixNotInitialized(OP_SUBSTRACT);
		}

		for (int i = 0, j; i < rowCount; i++) {
			for (j = 0; j < columnCount; j++) {
				retMatrix.rowPtr[i][j] -= other.rowPtr[i][j];
			}
		}
		return std::move(retMatrix);
	}

	template <typename T>
	CMatrix<T> CMatrix<T>::unaryOperation() const {

		CMatrix<T> retMatrix(*this);

		if (!isInitialized(retMatrix)) {
			throw MatrixNotInitialized(OP_UNARY);
		}

		for (int i = 0, j; i < rowCount; i++) {
			for (j = 0; j < columnCount; j++) {
				retMatrix.rowPtr[i][j] *= (-1);
			}
		}
		return std::move(retMatrix);
	}

	template <typename T>
	CMatrix<T> CMatrix<T>::transponseOperation() const {
		CMatrix<T> retMatrix(this->columnCount, this->rowCount, false);

		if (!isInitialized(retMatrix)) {
			throw MatrixNotInitialized(OP_TRANSPONSE);
		}

		for (int i = 0, j; i < rowCount; i++) {
			for (j = 0; j < columnCount; j++) {
				retMatrix[j][i] = this->rowPtr[i][j];
			}
		}

		return std::move(retMatrix);
	}

	template <typename T>
	CMatrix<T> CMatrix<T>::powerOperation(int power) const {

		if (power < 0) {
			throw WrongArgument(OP_POWER, power);
		}

		if (!equalDimensions()) {
			throw NotSquareMatrix(OP_POWER, getDims());
		}

		if (power == 0) {
			return std::move(CMatrix<T>(rowCount, (T)1));
		}
		else {
			CMatrix<T> retMatrix(*this);

			if (!isInitialized(retMatrix)) {
				throw MatrixNotInitialized(OP_POWER);
			}

			for (int k = 1; k < power; k++) {
				retMatrix = retMatrix * (*this);
			}

			return std::move(retMatrix);
		}

	}

	template <typename T>
	CMatrix<T> CMatrix<T>::dotProductOperation(const CMatrix<T>& other) const {

		if (!(this->rowCount == other.rowCount)) {
			throw DimensionMismatchException(OP_DOT_PRODUCT, getDims(), other.getDims());
		}

		return std::move(this->transponse() * other);
	}

	template <typename T>
	CMatrix<T>::CMatrix(T** newRowPtr, int rowCnt, int colCnt) {
		rowPtr = newRowPtr;
		rowCount = rowCnt;
		columnCount = colCnt;
	}

	template <typename T>
	CMatrix<T>::CMatrix(int rowCnt, int colCnt, bool randInit) {
		if (allocateMemory(rowCnt, colCnt)) {
			if (randInit) {
				populateMatrixWithRandomNumbers();
			}
		}
	}

	template <typename T>
	CMatrix<T>::CMatrix(int rowCnt, T diagonal) {
		if (allocateMemory(rowCnt, rowCnt)) {
			for (int i = 0, j = 0; i < rowCnt; i++) {
				for (j = 0; j < rowCnt; j++) {
					if (i == j) {
						rowPtr[i][j] = diagonal;
					}
					else {
						rowPtr[i][j] = 0;
					}
				}

			}
		}
	}

	template <typename T>
	CMatrix<T>::CMatrix(const CMatrix& other) {
		copyOperation(other);
	}

	template <typename T>
	CMatrix<T>::CMatrix(CMatrix&& other) noexcept {
		moveOperation(std::forward<CMatrix>(other));
	}

	template <typename T>
	CMatrix<T>::~CMatrix() {
		deallocateMemory();
	}

	template <typename T>
	const CMatrix<T>& CMatrix<T>::operator=(const CMatrix& other) {
		if (this != &other) {
			if (this->rowPtr != nullptr) {
				deallocateMemory();
			}
			copyOperation(other);
		}
		return *this;
	}

	template <typename T>
	const CMatrix<T>& CMatrix<T>::assignMatrix(const CMatrix& other) {
		if (this != &other) {
			if (this->rowPtr != nullptr) {
				deallocateMemory();
			}
			copyOperation(other);
		}
		return *this;
	}

	template <typename T>
	const CMatrix<T>& CMatrix<T>::operator=(CMatrix<T>&& other) noexcept {
		if (this != &other) {
			if (this->rowPtr != nullptr) {
				deallocateMemory();
			}
			moveOperation(std::forward<CMatrix>(other));
		}
		return *this;
	}

	template <typename T>
	const CMatrix<T>& CMatrix<T>::moveMatrix(CMatrix<T>&& other) {
		if (this != &other) {
			if (this->rowPtr != nullptr) {
				deallocateMemory();
			}
			moveOperation(std::forward<CMatrix>(other));
		}
		return *this;
	}

	template <typename T>
	const CMatrix<T>& CMatrix<T>::operator=(T diagonal) {
		diagonalOperation(diagonal);
		return *this;
	}

	template <typename T>
	const CMatrix<T>& CMatrix<T>::toDiagonal(T diagonal) {
		diagonalOperation(diagonal);
		return *this;
	}

	template <typename T>
	void CMatrix<T>::set(int rowIndex, int columnIndex, T newVal) {
		if (!isInitialized()) {
			throw MatrixNotInitialized(OP_SET);
		}
		else if (columnIndex >= columnCount || columnIndex < 0
			|| rowIndex >= rowCount || rowIndex < 0) {
			throw TwoWrongArguments(OP_SET, rowIndex, columnIndex);
		}
		rowPtr[rowIndex][columnIndex] = newVal;
	}

	template <typename T>
	T CMatrix<T>::get(int rowIndex, int columnIndex) {
		if (!isInitialized()) {
			throw MatrixNotInitialized(OP_GET);
		}
		else if (columnIndex >= columnCount || columnIndex < 0
			|| rowIndex >= rowCount || rowIndex < 0) {
			throw TwoWrongArguments(OP_GET, rowIndex, columnIndex);
		}
		return rowPtr[rowIndex][columnIndex];
	}

	template <typename T>
	CMatrix<T> CMatrix<T>::getRowVector(int rowIndex) {
		if (!isInitialized()) {
			return CMatrix(nullptr, 0, 0);
		}

		if (rowIndex >= rowCount || rowIndex < 0) {
			throw WrongArgument(OP_GET_ROW, rowIndex);
		}

		T** newRowPtr = new(std::nothrow) T * [1];
		if (newRowPtr != nullptr) {
			newRowPtr[0] = new(std::nothrow) T[columnCount];

			if (newRowPtr[0] != nullptr) {

				CMatrix retMatrix(newRowPtr, 1, columnCount);

				for (int i = 0; i < columnCount; i++) {
					retMatrix.set(0, i, this->rowPtr[rowIndex][i]);
				}
				return std::move(retMatrix);
			}
			else {
				delete[] newRowPtr;
			}
		}
		return CMatrix(nullptr, 0, 0);
	}

	template <typename T>
	CMatrix<T> CMatrix<T>::getColumnVector(int columnIndex) {
		if (!isInitialized()) {
			return CMatrix(nullptr, 0, 0);
		}
		if (columnIndex >= rowCount || columnIndex < 0) {
			throw WrongArgument(OP_GET_COLUMN, columnIndex);
		}

		T** newColumnPtr = new(std::nothrow) T * [rowCount];
		if (newColumnPtr != nullptr) {
			int i = 0;
			for (; i < rowCount; i++)
			{
				newColumnPtr[i] = new T[1];
				if (newColumnPtr[i] == nullptr) {
					for (; i > 0; i--) {
						delete[] newColumnPtr[i];
					}
					delete[] newColumnPtr;
					return CMatrix(nullptr, 0, 0);
				}
			}

			CMatrix retMatrix(newColumnPtr, rowCount, 1);
			if (!isInitialized(retMatrix)) {
				return CMatrix(nullptr, 0, 0);
			}
			for (i = 0; i < rowCount; i++)
			{
				retMatrix.set(i, 0, this->rowPtr[i][columnIndex]);
			}
			return std::move(retMatrix);
		}
		else {
			return CMatrix(nullptr, 0, 0);
		}
	}

	template <typename T>
	FileError CMatrix<T>::readMatrixFromFile(std::string fileName) {

		if (rowPtr != nullptr) {
			deallocateMemory();
		}

		std::ifstream fileHandler;
		fileHandler.open(fileName);
		if (!fileHandler.is_open()) {
			return FileError(FileErrorCode::FILE_NOT_OPEN);
		}

		int fileRowCount = 0, fileColumnCount = 0;

		std::string bufer = "";
		std::stringstream stream;

		if (!std::getline(fileHandler, bufer)) {
			fileHandler.close();
			return FileError(FileErrorCode::BAD_FIRST_GETLINE);
		}
		fileRowCount++;

		stream << bufer;
		bufer = "";
		//find column count
		stream >> bufer;
		while (!stream.eof()) {
			fileColumnCount++;
			bufer = "";
			stream >> bufer;
		}

		if (fileColumnCount < 1) {
			fileHandler.close();
			return FileError(FileErrorCode::BAD_COLUMN_COUNT);
		}

		//find row count
		while (std::getline(fileHandler, bufer)) {
			fileRowCount++;
		}

		// if dimensions are correct, allocate memory
		if (!allocateMemory(fileRowCount, fileColumnCount)) {
			fileHandler.close();
			return FileError(FileErrorCode::BAD_MEM_ALLOC);
		}

		fileHandler.clear();
		fileHandler.seekg(0);
		stream = std::stringstream();
		//load values from file into matrix
		T val = 0;
		for (int i = 0, j; i < rowCount; i++) {
			if (!std::getline(fileHandler, bufer)) {
				deallocateMemory();
				fileHandler.close();
				return FileError(FileErrorCode::BAD_GETLINE);
			}

			stream << bufer;
			bufer = "";
			for (j = 0; j < columnCount; j++) {
				stream >> bufer;
				if (!(std::stringstream(bufer) >> val)) {
					deallocateMemory();
					fileHandler.close();
					return FileError(FileErrorCode::READ_BAD_VALUE);
				}
				rowPtr[i][j] = val;
				bufer = "";
			}
			stream = std::stringstream();
		}

		fileHandler.close();

		return FileError(FileErrorCode::OK);
	}


	template <typename T>
	void CMatrix<T>::display() const {
		for (int i = 0, j = 0; i < rowCount; i++) {
			for (j = 0; j < columnCount; j++) {
				std::cout << rowPtr[i][j] << SEPARATOR;
			}
			std::cout << std::endl;
		}
	}











}



