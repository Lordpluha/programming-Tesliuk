#include "lib.h"

/**
 * @file main.c
 * @author Tesliuk Vladyslav
 * @date 12-may-2024
 * @version 1.0.0
 */

/**
 * @brief Entrypoint програми
 * 11. (\*\*)  Визначити об’єм запитаного каталогу.  Результат нормалізувати.  Формат розміру:
 *  - не більше ніж 3 знаки  до коми;
 *  - не більше ніж 2 знаки  після  коми;
 *  - єдиний  випадок,  коли  в  чисельний  частині  числа  може  бути  0  -  коли  розмір  дорівнює 0  байт.
 */
int main(int argc, char *argv[]) {
	preview();

	// Перевірка наявності аргументів командного рядка
    if (argc != 3) {
        printf("Usage: %s <directory> <output_file>\n", argv[0]);
        return 1;
    }

    // Отримання шляху до вхідного файлу та файлу для запису результатів
    char *input_file = argv[1];
    char *output_file = argv[2];

    // Відкриття вхідного файлу для читання
    FILE *input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Отримання розміру вхідного файлу
    fseek(input_fp, 0L, SEEK_END);
    long input_file_size = ftell(input_fp);
    fseek(input_fp, 0L, SEEK_SET);

    // Визначення розміру буфера на основі розміру вхідного файлу
    char *buffer = (char *)malloc((unsigned long)input_file_size * sizeof(char));

    // Читання даних з вхідного файлу у буфер
    read_from_file(input_fp, buffer, (int)input_file_size);

    // Закриття вхідного файлу
    fclose(input_fp);

    // Обчислення об'єму запитаного каталогу
    float directory_size = calculate_directory_size(argv[0]);

    // Відкриття вихідного файлу для запису
    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        perror("Error opening output file");
        return 1;
    }

    // Запис результатів у вихідний файл
    fprintf(output_fp, "Directory size: %s\n", format_file_size(directory_size));

    // Закриття вихідного файлу
    fclose(output_fp);

    // Звільнення виділеної пам'яті для буфера
    free(buffer);

	return 0;
}
