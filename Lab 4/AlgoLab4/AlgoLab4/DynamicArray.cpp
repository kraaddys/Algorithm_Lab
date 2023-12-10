#include "DynamicArray.h"


DynamicArray::DynamicArray() {
	capacity = 16;
	size = 0;
	container = new int[capacity];
}

DynamicArray:: ~DynamicArray() {
	cout << "\nDEBUG MSG" << endl;
	delete[] container;
}

int DynamicArray::getCapacity()
{
	return capacity;
}

int DynamicArray::getSize()
{
	return size;
}

void DynamicArray::pushBack(int num)
{
	if (!checkSize()) {
		int newCapacity = size * 2;
		int* newContainer = new int[newCapacity] {};
		for (int i = 0; i < size; i++) {
			newContainer[i] = container[i];
		}
		delete[] container;
		container = newContainer;
		newContainer = nullptr;
	}
	container[size++] = num;

}

int& DynamicArray::operator[](int index)
{
	if (index >= size || index < 0) {
		int error = std::numeric_limits<int>::max();
		return error;
	}
	return container[index];
}

bool DynamicArray::checkSize()
{
	return size < capacity;
}

ostream& operator<<(ostream& out, const DynamicArray& array)
{
	for (int i = 0; i < array.size; i++) {
		out << array.container[i] << "\t";
	}
	return out;
}
