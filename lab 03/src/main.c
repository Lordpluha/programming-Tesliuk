#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * 21. Прямокутник заданий координатами своїх вершин (x1, y1, x2, y2, x3, y3, x4, y4).
 * 	   Знайти периметр P і площу S прямокутника.
 * 	   Враховуємо, що сторони прямокутника паралельні осям координат.
 * Виковнав: Теслюк Владислав Андрiйович КН-923г
*/
int main() {
	// Инициализация переменных
	int x1, y1, x2, y2, x3, y3, x4, y4;

	// Запрашиваем данные
	for (int i = 1; i<=4; i++) {
		printf("[%d]Input point 'x y':\n", i);
		char scan_markup[10] = "%d %d";
		switch (i) {
			case 1:
				scanf(scan_markup, &x1, &y1);
				break;
			case 2:
				scanf(scan_markup, &x2, &y2);
				break;
			case 3:
				scanf(scan_markup, &x3, &y3);
				break;
			case 4:
				scanf(scan_markup, &x4, &y4);
				break;
		}
		
		printf("\n");
	}
	
	// Первая сторона прямоугольника
	int x_f = abs(x1-x2);
	int y_f = abs(y1-y2);
	double side1 = sqrt(pow(x_f, 2) + pow(y_f, 2));

	// Вторая сторона прямоугольника
	int x_s = abs(x2-x3);
	int y_s = abs(y2-y3);
	double side2 = sqrt(pow(x_s, 2) + pow(y_s, 2));

	// Вычисление результатов
	double P = 2*(side1 + side2);
	double S = side1*side2;
	
	// Вывод результатов
	printf("P = %lf\n", P);
	printf("S = %lf\n", S);

	return 0;
}