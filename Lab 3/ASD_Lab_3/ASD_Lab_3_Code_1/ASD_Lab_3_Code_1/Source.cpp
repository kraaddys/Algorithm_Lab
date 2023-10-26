#include <iostream>

using namespace std;

int hello(int input) {

	return input;
}

int main() {

	int result = hello(20);
	cout << "Result: " << result << endl;
	return 0;
}