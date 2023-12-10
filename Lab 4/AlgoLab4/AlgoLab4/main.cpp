#include "Includes.h"
#include "DynamicArray.h"

int main() {
	DynamicArray array;
	cout << "Capacity = " << array.getCapacity() << endl;

	for (int i = 0; i <= 10; i++) {
		array.pushBack(i);
	}
	cout << array;

	assert(array.getSize() == 11);
	assert(array[0] == 0);
	return 0;
}
