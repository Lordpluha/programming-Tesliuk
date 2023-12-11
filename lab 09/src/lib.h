/* lib.h */
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/**
 * Слід звернути увагу: параметри одного з викликів функції повинні бути згенеровані за допомогою генератора псевдовипадкових чисел random().
 * Слід звернути увагу (#2): продемонструвати встановлення вхідних даних через аргументи додатка (параметри командної строки). Обробити випадок, коли дані не передались - у цьому випадку вони матимуть значення за умовчуванням, обраними розробником.
 * 
 * 1. Реалізувати функцію (та продемонструвати її роботу), що визначає, скільки серед заданої послідовності чисел таких пар, у котрих перше число менше наступного, використовуючи функцію з варіативною кількістю аргументів. • Наприклад, при вхідних даних { 3, 2, 4, 3, 1 }, результат повинен бути 3 (тобто наступні пари чисел: 3, 2, 4, 3, 3, 1)
 */

/// Определение структуры передачи параметров массива между функциями
struct arrayParams {
	int lenght;
	int* array;
};

#ifndef isDigit
#define isDigit

/// Функция для проверки являеться ли символ цифрой
bool isDigit(char myChar);

#endif /*isDigit*/

#ifndef stringToIntArray
#define stringToIntArray
#define memorySize 100

/// Функция для парсинга чисел в строке в массив чисел без лишних символов
struct arrayParams stringToIntArray(char charArray[memorySize]);

#endif /*stringToIntArray*/

#ifndef countDescendOrderPairs
#define countDescendOrderPairs

/// Функция для вычисления количества пар уменьшающихся чисел
int countDescendOrderPairs(struct arrayParams opts);

#endif /*countDescendOrderPairs*/
 
