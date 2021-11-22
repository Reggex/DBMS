#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

/**
	 * \brief Инициализация размера массива.
	 * \param string Текст вводного сообщения.
	 * \return Размер массива.
	 */
size_t get_size(const string& message)
{
	int size;
	cout << message <<endl;
	cin >> size;
	while (size < 0) {
		cout << "Incorrect size. Value has to be greater or equal zero." << endl;
		cin >> size;
	}
	
	return size;
}

/**
	 * \brief Заполнение массива рандомными значениями.
	 * \param array Массив.
	 * \param size Размер массива.
	 */
void fillArray(char* array, int size) {
	char random_char;
	unsigned seed = time(0);
	srand(seed);
	for (int i = 0; i < size; ++i) {
		random_char = 32 + rand() % 94;
		array[i] = random_char;
	}
}

/**
	 * \brief Вывод массива на экран.
	 * \param array Массив.
	 * \param size Размер массива.
	 */
void printArray(char* array, int size) {
	cout << "Your array:" << endl;
	for (int i = 0; i < size; ++i) {
		cout << "' " << array[i] << " '";
	}
	cout << endl;
}

/**
	 * \brief Находит максимальный элемент в массиве.
	 * \param array Массив.
	 * \param size Размер массива.
	 * \return Максимальный элемент.
	 */
char getMaxElement(char* array, int size)
{
	char max_element = array[0];
	for (int i = 0; i < size; ++i) {
		if (array[i] > max_element) {
			max_element = array[i];
		}
	}
	return max_element;
}

/**
	 * \brief Главная программа.
	 * \return 0 в случае успеха.
	 */
int main() {
	int size;
	size = get_size("Input size of the array, what you want.");
	char* array = new char [size];
	fillArray(array, size);
	printArray(array, size);
	cout << "Max element of array is ' " << getMaxElement(array, size) << " '" << endl;
	if (array != nullptr)
	{
		delete[] array;
		array = nullptr;
	}
	return 0;
}
