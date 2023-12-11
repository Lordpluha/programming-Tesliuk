#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @file main.c
 * Слід звернути увагу: параметри одного з викликів функції повинні бути згенеровані за допомогою генератора псевдовипадкових чисел random().
 * Слід звернути увагу (#2): продемонструвати встановлення вхідних даних через аргументи додатка (параметри командної строки). Обробити випадок, коли дані не передались - у цьому випадку вони матимуть значення за умовчуванням, обраними розробником.
 * 
 * 1. Реалізувати функцію (та продемонструвати її роботу), що визначає, скільки серед заданої послідовності чисел таких пар, у котрих перше число менше наступного, використовуючи функцію з варіативною кількістю аргументів. • Наприклад, при вхідних даних { 3, 2, 4, 3, 1 }, результат повинен бути 3 (тобто наступні пари чисел: 3, 2, 4, 3, 3, 1)
 * @author Tesliuk
 * @date 8-dec-2023
 * @version 1.0.3
 */

/// Розмiр пам`ятi для програми
#define memorySize 100

/// Визначення структури передачі параметрів масиву між функціями
struct arrayParams {
	int lenght; ///< Довжина масиву
	int* array; ///< Вказiвник на массив
};

/**
 * @brief Функцiя для перевiрки чи е символ цифрою
 * @param myChar char - символ, який треба перевiрити
 * @return boolean
 */ 
bool isDigit(char myChar) {
	return (myChar != '{' && myChar != '}' && myChar != ',' && myChar != ' ');
}

/**
 * @brief Функцiя для парсингу чисел з строки в масив чисел без зайвих символiв
 * @param charArray char[] - строка для конвертацii
 * @return struct arrayParams - массив та його довжина
 */
struct arrayParams stringToIntArray(char charArray[memorySize]) {
	// Довжина масиву в фороматi size_t (для calloc) и int(для звичайного перебору)
	size_t lenghtSize = 0;
	// Довжина масиву 
	int lenght = 0;

	// Чи е цифра частиною числа
	bool isNumber = false;
	
	/// Обчислюем розмiр майбутнього массиву чисел
	for (int i = 0; charArray[i] != '\0'; i++) {
		if (isDigit(charArray[i])) {
			if (!isNumber) {
				lenghtSize++;
				lenght++;
				isNumber = true;
			}
			continue;
		}
		isNumber = false;
	}

	/// Создаемо массив розмiром lenghtSize
	int* intArray = (int*)calloc(lenghtSize, sizeof(int));
	
	// Змiнна чи е цифра частиною числа
	isNumber = false;
	// Додаткова змiнна - буфер
	char buffer [100];
	// Утилiтi змiнна
	int n;
	// Змiнна iндексу початка числа
	int previousStartDigitIndex;

	/// Переводимо данi з charArray в intArray
	for (int i = 0, a = 0; charArray[i] != '\0'; i++) {
		if (isDigit(charArray[i])) {
			if(isNumber) {
				// Все наступнi цифри
				n=sprintf(buffer, "%d%c", intArray[previousStartDigitIndex], charArray[a]);
				intArray[previousStartDigitIndex] = atoi(buffer);
			} else {
				// Перша цифра
				previousStartDigitIndex = a;
				intArray[a] = atoi(&charArray[i]);
				a++;
			}
			isNumber = true;
			continue;
		}
		isNumber = false;
	}

	/// Визначення структури для возврату множини параметрiв
	struct arrayParams params;

	/// Передаемо параметри в структуру
	params.lenght = lenght;
	params.array = intArray;

	/// Вертаемо структуру
	return params;
}

/**
 * @brief Функцiя для обрахування кiлькостi пар зменьшуючихся чисел
 * @param opts - структура типу arrayParams
 * @return int - результат обрахувань
 */
int countDescendOrderPairs(struct arrayParams opts) {
	/// Деструктуризуемо данi
	int lenght = opts.lenght;
	int *array = opts.array;
	
	/// Обчислюемо кiлькiсть пар
	int res = 0;
	for (int i = 0; i < (lenght - 1); i++) {
		if (array[i] > array[i+1]) {
			res++;
		}
	}

	/// Вертаемо результат
	return res;
}

/**
 * @brief Точка входу програми
*/
int main() {
	/// Iнiцiалiзацiя змiнних
	char charArray1[memorySize];

	/// Запит даних
	printf("[1.1] - Input your array:\n");
	printf("	Info:\n");
	printf("		You can use array formats:\n");
	printf("			- {nums1, num2, ...}\n");
	printf("			- num1, num2, ...\n");
	printf("			- num1,num2,...\n");
	printf("			- num1 num2 ...\n");
	scanf("%[^\n]%*c", charArray1);

	/// Перевiрка на заповненнiсть строки даними
	if (strlen(charArray1) != 0 && charArray1[0] != ' ') {
		/// Обчислення результату за допомогою функцiй
		int res = countDescendOrderPairs(stringToIntArray(charArray1));
		printf("[1.1] - Result: %d\n", res);
	}
	
	/// Тест з рандомними числами
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