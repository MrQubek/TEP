#pragma once

class ReferenceCounter
{
private:
	int count;
public:
	ReferenceCounter() { count = 0; }
	int add() { return(++count); }
	int dec() { return(--count); }
	int get() { return(count); }
};

template <typename T> class SmartPointer
{
private:
	ReferenceCounter* ptrCounter;
	T* ptrObject;
public:
	SmartPointer<T>(T* pointer);

	SmartPointer<T>(const SmartPointer<T>& other);

	~SmartPointer();

	T& operator*() { return(*ptrObject); }

	T* operator->() { return(ptrObject); }

	SmartPointer<T>& operator = (const SmartPointer<T>& other);

	SmartPointer<T> duplicate();

};

template <typename T>
SmartPointer<T>::SmartPointer(T* pointer)
{
	ptrObject = pointer;
	ptrCounter = new ReferenceCounter();
	ptrCounter->add();
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& other)
{
	ptrObject = other.ptr;
	ptrCounter = other.ptrCounter;
	ptrCounter->add();
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
	if (ptrCounter->dec() == 0)
	{
		delete ptrObject;
		delete ptrCounter;
	}
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator = (const SmartPointer<T>& other) {
	if (this != &other) {
		if (ptrCounter->dec() == 0)
		{
			delete ptrObject;
			delete ptrCounter;
		}

		ptrObject = other.ptrObject;
		ptrCounter = other.ptrCounter;
		ptrCounter->add();
	}
	return *this;
}

template <typename T>
SmartPointer<T> SmartPointer<T>::duplicate() {
	return SmartPointer<T>(new T(*ptrObject));
}
