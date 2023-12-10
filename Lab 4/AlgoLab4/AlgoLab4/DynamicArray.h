#pragma once
#include"Includes.h"
class DynamicArray
{
	int capacity;
	int size;
	int* container;
	bool checkSize();
public:
	DynamicArray();
	~DynamicArray();
	int getCapacity();
	int getSize();
	void pushBack(int num);

	friend ostream& operator<< (ostream& out, const DynamicArray& array);
	int& operator[](int index);
};

