#include "lib.h"

/**
 * @file lib.c
 * @author Tesliuk Vladyslav
 * @date 12-may-2024
 * @version 1.0.0
 */

/**
 * @brief Функцiя для виведення базової iнформацiї програми
 */
void preview() {
    FILE *file = fopen("assets/input.txt", "r");
    if (file == NULL) {
        printf("Помилка відкриття файлу assets/input.txt");
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

/**
 * @brief Функція для перетворення рядка у ціле число
 */
int str_to_int(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Перевірка на від'ємне число
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    // Проходження по символам рядка і будування числа
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
        i++;
    }

    return result * sign;
}

/// Функція для перетворення рядка у число з плаваючою комою
float str_to_float(const char *str) {
    float result = 0.0;
    float fraction = (float) 0.1;
    int i = 0;
    int sign = 1;

    // Перевірка на від'ємне число
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    // Проходження по символам рядка і будування числа
    while (str[i] != '\0' && str[i] != '.') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
        i++;
    }

    if (str[i] == '.') {
        i++;
        while (str[i] != '\0') {
            if (str[i] >= '0' && str[i] <= '9') {
                result = result + (str[i] - '0') * fraction;
                fraction *= (float) 0.1;
            }
            i++;
        }
    }

    return result * sign;
}
