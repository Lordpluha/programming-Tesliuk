#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Слід звернути увагу: параметри одного з викликів функції повинні бути згенеровані за допомогою генератора псевдовипадкових чисел random().
 * Слід звернути увагу (#2): продемонструвати встановлення вхідних даних через аргументи додатка (параметри командної строки). Обробити випадок, коли дані не передались - у цьому випадку вони матимуть значення за умовчуванням, обраними розробником.
 * 
 * 1. Реалізувати функцію (та продемонструвати її роботу), що визначає, скільки серед заданої послідовності чисел таких пар, у котрих перше число менше наступного, використовуючи функцію з варіативною кількістю аргументів. • Наприклад, при вхідних даних { 3, 2, 4, 3, 1 }, результат повинен бути 3 (тобто наступні пари чисел: 3, 2, 4, 3, 3, 1)
 */

#define memorySize 100

/// Определение структуры передачи параметров массива между функциями
struct arrayParams {
	int lenght;
	int* array;
};

/// Функция для проверки являеться ли символ цифрой
bool isDigit(char myChar) {
	return (myChar != '{' && myChar != '}' && myChar != ',' && myChar != ' ');
}

/// Функция для парсинга чисел в строке в массив чисел без лишних символов
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
	char buffer [100];
	int n;
	int previousStartDigitIndex;
	for (int i = 0, a = 0; charArray[i] != '\0'; i++) {
		if (isDigit(charArray[i])) {
			if(isNumber) {
				/// Все следущие цифры
				n=sprintf(buffer, "%d%c", intArray[previousStartDigitIndex], charArray[a]);
				intArray[previousStartDigitIndex] = atoi(buffer);
			} else {
				/// Первая цифра
				previousStartDigitIndex = a;
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

/// Функция для вычисления количества пар уменьшающихся чисел
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

int main() {
	/// Инициализация переменных
	char charArray1[memorySize];

	/// Запрос данных
	printf("[1.1] - Input your array:\n");
	printf("	Info:\n");
	printf("		You can use array formats:\n");
	printf("			- {nums1, num2, ...}\n");
	printf("			- num1, num2, ...\n");
	printf("			- num1,num2,...\n");
	printf("			- num1 num2 ...\n");
	scanf("%[^\n]%*c", charArray1);

	/// Проверка на заполнение строки данными
	if (strlen(charArray1) != 0 && charArray1[0] != ' ') {
		/// Вычисление результата с помощь функций
		int res = countDescendOrderPairs(stringToIntArray(charArray1));
		printf("[1.1] - Result: %d\n", res);
	}
	
	/// Тест с рандомными числами
	int randList[10];
	printf("[1.2] - Test random 10 numbers:\n");
	for (int i = 0; i < 10; i++) {
		randList[i] = rand();
		printf("%d, ", randList[i]);
	}
	struct arrayParams randParams;
	randParams.lenght = 10;
	randParams.array = randList;
	int randRes = countDescendOrderPairs(randParams);
	printf("\n[1.2] - Result: %d\n", randRes);

	return 0;
}