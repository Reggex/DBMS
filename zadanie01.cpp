#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void maxElement(char* array, int size)
{
	char max_element = array[0];
	for (int i = 0; i < size; ++i) {
		if (array[i] > max_element) {
			max_element = array[i];
		}
	}
	cout << "Max element of array is ' " << max_element << " '" << endl;
}

void fillArray(char* array, int size) {
	char random_char;
	unsigned seed = time(0);
	srand(seed);
	for (int i = 0; i < size; ++i) {
		random_char = 32 + rand() % 94;
		array[i] = random_char;
	}
}

void printArray(char* array, int size) {
	cout << "Your array:" << endl;
	for (int i = 0; i < size; ++i) {
		cout << "' " << array[i] << " '";
	}
	cout << endl;
}

int main() {
	cout << "Input size of the array, what you want." << endl;
	int size;
	cin >> size;
	char* array = new char [size];
	fillArray(array, size);
	printArray(array, size);
	maxElement(array, size);
	delete[] array;
	system("pause");
	return 0;
}
