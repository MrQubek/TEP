#pragma once

class CRefCounter
{
private:
	int count;
public:
	CRefCounter() { count = 0; }
	int add() { return(++count); }
	int dec() { return(--count); }
	int get() { return(count); }
};

template <typename T> class SmartPointer
{
private:
	CRefCounter* ptrCounter;
	T* ptr;
public:
	SmartPointer<T>(T* pointer)
	{
		ptr = pointer;
		ptrCounter = new CRefCounter();
		ptrCounter->add();
	}

	SmartPointer<T>(const SmartPointer<T>& other)
	{
		ptr = other.ptr;
		ptrCounter = other.ptrCounter;
		ptrCounter->add();
	}

	~SmartPointer()
	{
		if (ptrCounter->dec() == 0)
		{
			delete ptr;
			delete ptrCounter;
		}
	}
	
	T& operator*() { return(*ptr); }
	
	T* operator->() { return(ptr); }

	SmartPointer<T>& operator = (const SmartPointer<T>& other) {
		if (ptrCounter->dec() == 0)
		{
			delete ptr;
			delete ptrCounter;
		}

		ptr = other.ptr;
		ptrCounter = other.ptrCounter;
		ptrCounter->add();
		return *this;
	}

};
