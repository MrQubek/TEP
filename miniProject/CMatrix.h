#pragma once

#include<utility>
#include<string>
#include<cstdlib>
#include<time.h>
#include <random>
#include <iostream>

#include "const.h"


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
		// warning: possible memory leaks if memory was already allocated
		bool allocateMemory(int rowCnt, int colCnt);

		void populateMatrixWithRandomNumbers();

		void copyMatrixValues(const CMatrix& other);

	public:
		static const float ALG_PRECISION;

		// =========================================================================
		// Constructors:
		// =========================================================================

		// create matrix with (possible) random values
		CMatrix(int rowCnt, int colCnt, bool randInit = false);

		// create square diagonal matrix
		CMatrix(int rowCnt, T diagonal);

		CMatrix(const CMatrix& other);

		CMatrix(CMatrix&& other);

		~CMatrix();

		CMatrix createMatrix(int rowCnt, int colCnt, bool randInit = false) {
			return std::move(CMatrix(rowCnt, colCnt, randInit));
		}

		// =========================================================================
		// Assign operators:
		// =========================================================================

		const CMatrix& operator=(const CMatrix& other);

		// switch matrix to square diagonal matrix 
		const CMatrix& operator=(T diagonal);

		const CMatrix& toDiagonal(T diagonal);

		// move operator
		const CMatrix& operator=(CMatrix&& other);


		// =========================================================================
		// indexing matrix
		// =========================================================================

		T* operator[](int row_ind);

		T* getRow(int row_ind);

		void set(int x, int y, T newVal) {
			if (rowPtr != nullptr)rowPtr[x][y] = newVal;
		}

		T get(int x, int y) {
			//if (rowPtr != nullptr && x < columnCount && y < rowCount)
			return rowPtr[x][y];
		}

		// =========================================================================
		// return vector matrix from rows/columns
		// =========================================================================

		CMatrix getRowVector(int rowIndex);

		CMatrix getColumnVector(int columnIndex);

		// =========================================================================
		// algebraic operations
		// =========================================================================

		CMatrix operator*(const CMatrix& other) const;
		CMatrix multiply(const CMatrix& other) const;

		// multiply matrix by constant
		CMatrix operator*(T multiplier) const;
		CMatrix multiply(T multiplier) const;


		CMatrix operator+(const CMatrix& other) const;
		CMatrix add(const CMatrix& other) const;

		CMatrix operator-(const CMatrix& other) const;
		CMatrix substract(const CMatrix& other) const;


		// change sign of all elements of matrix
		CMatrix operator-() const;

		CMatrix unary() const;

		// transponse matrix
		CMatrix operator~() const;

		CMatrix transponse() const;

		// accept only power >= 0:
		//    power = 0  - return unity matrix
		//    power = 1  - return copy of matrix
		//    power > 1  - return power of matrix
		CMatrix operator^(int power) const;

		CMatrix power(int power) const;

		// dot product (iloczyn skalarny) A^T*B
		CMatrix dotProduct(const CMatrix& other) const;

		// compare matrix with accuracy to ALG_PRECISION
		bool operator==(const CMatrix& rhs) const;

		bool compareTo(const CMatrix& rhs) const;

		// =========================================================================
		// algebraic operations
		// =========================================================================

		bool readMatrixFromFile(std::string fileName);

		// only for tests - display matrix by rows on stdout
		void display() const;

		// friend CMtx operator*( T multiplier, const CMtx &rhs );
	};

	//template <typename T>
	//CMatrix<T> operator*(T multiplier, const CMatrix<T>& rhs);

	// =========================================================================
	// methods declarations
	// =========================================================================

	template <typename T>
	bool CMatrix<T>::allocateMemory(int rowCnt, int colCnt) {

		if (rowCnt < 0 || colCnt < 0) {
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
					delete rowPtr;
					rowPtr = nullptr;
					return false;
				}
			}
		}
		return true;
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
	CMatrix<T>::CMatrix(int rowCnt, int colCnt, bool randInit) {

		if (allocateMemory(rowCnt, colCnt)) {
			this->rowCount = rowCnt;
			this->columnCount = colCnt;

			if (randInit) {
				srand((unsigned int)time(0));
				populateMatrixWithRandomNumbers();
			}
		}
		else {
			this->rowCount = 0;
			this->columnCount = 0;
		}
	}

	template <typename T>
	CMatrix<T>::CMatrix(int rowCnt, T diagonal) {

		if (allocateMemory(rowCnt, rowCnt)) {
			this->rowCount = rowCnt;
			this->columnCount = rowCnt;

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
		else {
			this->rowCount = 0;
			this->columnCount = 0;
		}
	}

	template <typename T>
	CMatrix<T>::CMatrix(const CMatrix& other) {
		if (allocateMemory(other.rowCount, other.columnCount)) {
			this->rowCount = other.rowCount;
			this->columnCount = other.columnCount;

			copyMatrixValues(other);

		}
		else {
			this->rowCount = 0;
			this->columnCount = 0;
		}
	}


	template <typename T>
	CMatrix<T>::~CMatrix() {
		for (int i = 0; i < rowCount; i++) {
			delete[] rowPtr[i];
		}
		delete[] rowPtr;
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


