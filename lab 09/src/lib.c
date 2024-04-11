#include "lib.h"

bool isDigit(char myChar) {
	return (myChar != '{' && myChar != '}' && myChar != ',' && myChar != ' ');
}

struct arrayParams stringToIntArray(char charArray[memorySize]) {
	/// Длина массива в форомате size_t (для calloc) и int(для обычного перебора)
	size_t lenghtSize = 0;
	int lenght = 0;

	/// Являеться ли цифра частью числа
	bool isNumber = false;
	
	/// Вычисляем размер будущего массива чисел
	for (int i = 0; charArray[i] != '\0'; i++) {
		if (isDigit(charArray[i]))
		{
			if (!isNumber) {
				lenghtSize++;
				lenght++;
				isNumber = true;
			}
			continue;
		}
		isNumber = false;
	}

	/// Создаем массив размерностью lenghtSize
	int* intArray = (int*)calloc(lenghtSize, sizeof(int));
	
	/// Перемещаем данные из charArray в intArray
	isNumber = false;
	char buffer [memorySize];
	int n;
	int previous_start_digit_index;
	for (int i = 0, a = 0; charArray[i] != '\0'; i++) {
		if (isDigit(charArray[i])) {
			if(isNumber) {
				/// Все следущие цифры
				n=sprintf(buffer, "%d%c", intArray[previous_start_digit_index], charArray[a]);
				intArray[previous_start_digit_index] = atoi(buffer);
			} else {
				/// Первая цифра
				previous_start_digit_index = a;
				intArray[a] = atoi(&charArray[i]);
				a++;
			}

			isNumber = true;
			continue;
		}
		isNumber = false;
	}

	/// Объявляем структуру для возврата множества параметров
	struct arrayParams params;

	/// Передаем параметры в структуру
	params.lenght = lenght;
	params.array = intArray;

	return params;
}

int countDescendOrderPairs(struct arrayParams opts) {
	/// Деструктуризируем данные
	int lenght = opts.lenght;
	int *array = opts.array;
	
	/// Вычисляем количество пар
	int res = 0;
	for (int i = 0; i < (lenght - 1); i++) {
		if (array[i] > array[i+1]) {
			res++;
		}
	}

	/// Возвращаем результат
	return res;
}
