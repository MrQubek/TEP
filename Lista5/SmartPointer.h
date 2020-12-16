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
	SmartPointer<T>(T* pointer)
	{
		ptrObject = pointer;
		ptrCounter = new ReferenceCounter();
		ptrCounter->add();
	}

	SmartPointer<T>(const SmartPointer<T>& other)
	{
		ptrObject = other.ptr;
		ptrCounter = other.ptrCounter;
		ptrCounter->add();
	}

	~SmartPointer()
	{
		if (ptrCounter->dec() == 0)
		{
			delete ptrObject;
			delete ptrCounter;
		}
	}

	T& operator*() { return(*ptrObject); }

	T* operator->() { return(ptrObject); }

	SmartPointer<T>& operator = (const SmartPointer<T>& other) {
		if (this != other) {
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

};
