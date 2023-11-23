#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 * 23. (**)  Визначити, чи є  задане ціле число простим.
*/
// Реалізувати програму за допомогою трьох типів циклів:  for, while-do, do-while (отримати три однакових результати)

int main() {
	// Инициализация переменных
	int num = 1;
	double numSqrt;

	// Запрашиваем данные
	printf("Input your number':\n");
	scanf("%d", &num);

	// Проверяем являеться ли число простым с помощью перебора до квадрата числа
	if(num == 1 || num == 2 || num == 3) {
		printf("Число просте");
		return 0;
	}
	numSqrt = sqrt(num);
	for (int i = 2; i < numSqrt; i++) {
		// Проверяем что число делиться нацело на наш елемент перебора
		if (num % i == 0) {
			printf("Число не просте");
			return 0;
		}
	}
	printf("Число просте");
	return 0;
}