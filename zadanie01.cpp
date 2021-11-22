#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

/**
	 * \brief Инициализация размера массива.
	 * \param string Текст вводного сообщения.
	 * \return Размер массива.
	 */
size_t get_size(const string& message);

/**
	 * \brief Заполнение массива рандомными значениями.
	 * \param array Массив.
	 * \param size Размер массива.
	 */
void fillArray(char* array, const size_t size);

/**
	 * \brief Вывод массива на экран.
	 * \param array Массив.
	 * \param size Размер массива.
	 */
void printArray(const char* array, const size_t size);

/**
	 * \brief Находит максимальный элемент в массиве.
	 * \param array Массив.
	 * \param size Размер массива.
	 * \return Максимальный элемент.
	 */
char getMaxElement(const char* array, const size_t size);

/**
	 * \brief Главная программа.
	 * \return 0 в случае успеха.
	 */
int main() {
	size_t size;
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

size_t get_size(const string& message)
{
	int size;
	cout << message << endl;
	cin >> size;
	while (size < 0) {
		cout << "Incorrect size. Value has to be greater or equal zero." << endl;
		cin >> size;
	}

	return size;
}

void fillArray(char* array, const size_t size)
{
	const int first_сharacter = 32;
	const int number_of_сharacters = 94;
	char random_char;
	unsigned seed = time(0);
	srand(seed);
	for (size_t i = 0; i < size; ++i) {
		random_char = first_сharacter + rand() % number_of_сharacters;
		array[i] = random_char;
	}
}

void printArray(const char* array, const size_t size)
{
	cout << "Your array:" << endl;
	for (size_t i = 0; i < size; ++i) {
		cout << "' " << array[i] << " '";
	}
	cout << endl;
}

char getMaxElement(const char* array, const size_t size)
{
	char max_element = array[0];
	for (size_t i = 0; i < size; ++i) {
		if (array[i] > max_element) {
			max_element = array[i];
		}
	}
	return max_element;
}
