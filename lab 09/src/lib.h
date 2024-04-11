#ifndef SAMPLE_PROJECT_LIB_H 
#define SAMPLE_PROJECT_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define memorySize 100

/// Функция для проверки являеться ли символ цифрой
bool isDigit(char myChar);

/// Определение структуры передачи параметров массива между функциями
struct arrayParams {
	int lenght;
	int* array;
};


/// Функция для парсинга чисел в строке в массив чисел без лишних символов
struct arrayParams stringToIntArray(char charArray[memorySize]);

/// Функция для вычисления количества пар уменьшающихся чисел
int countDescendOrderPairs(struct arrayParams opts);

#endif /* LIB_H */
