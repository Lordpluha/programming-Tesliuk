#include "lib.h"

int main() {
	/// Инициализация переменных
	char char_array1[memorySize];

	/// Запрос данных
	printf("Input your array:\n");
	scanf("%[^\n]%*c", char_array1);

	/// Проверка на заполнение строки данными
	if (strlen(char_array1) != 0 && char_array1[0] != ' ') {
		/// Вычисление результата с помощь функций
		int res = countDescendOrderPairs(stringToIntArray(char_array1));
		printf("Result: %d\n", res);
	}

	return 0;
}