#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

/*
 * 27.    (**)  Центрувати  заданий рядок на площині  з  із  заданим  заповнювачем.  Наприклад,
•    заповнювач = “_” ,
•    довжина строки  = 15,
•    рядок = ”Ivanov               \0” (6 символів слово “Ivanov”, 8 - пробілів, останній символ = ‘\0’)
•    результат = “____Ivanov____” (4 символи заповнювача, слово “Ivanov”, 4 символи заповнювача, останній  символ =  ‘\0’)
*/

// Инициализация констант
#define placeholder '_'
#define length 15


int main() {
	// Инициализация переменных
	char content;
	
	// Запрос данных
	printf("Content':\n");
	scanf("%s", &content);

	// Вычисления длинны первых заполнителей
	float firstPlaceholderLenght = roundf((length-strlen(&content))/2);

// Вывод результатов
	// Левая часть ответа
	for (int i = 0; i < firstPlaceholderLenght; i++) {
		printf("%c", placeholder);
	}
	// Контент
	printf("%s", &content);

	// Правая часть ответа
	for (int i = 0; i < firstPlaceholderLenght; i++) {
		printf("%c", placeholder);
	}
	return 0;
}