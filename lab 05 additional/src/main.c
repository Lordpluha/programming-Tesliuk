#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 * 1. Визначити значення  10𝑛! (10 * факторіал  числа  n).исло, бо  6  =  1 + 2 + 3.
*/
// Реалізувати програму за допомогою трьох типів циклів:  for, while-do, do-while (отримати три однакових результати)

int main() {
	// Инициализация переменных
	int num, res = 1;

	// Получаем число
	scanf("%d", &num);

	// Вычисляем факториал num
	for (int i = 1; i <= num; i++) {
		res *= i;
	}
	// Умножаем факториал на 10
	res *= 10;
	
	// Выводим результат
	printf("%d", res);

	return 0;
}