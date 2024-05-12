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
    FILE *file = fopen("../assets/input.txt", "r");
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

// Функція для зчитування з файлу
void read_from_file(FILE *f, char *result, int buf_size) {
    fread(result, sizeof(char), (unsigned long)buf_size, f);
}

// Функція для запису у файл
void write_to_file(FILE *f, char *data) {
    fprintf(f, "%s", data);
}

// Функція для обчислення об'єму запитаного каталогу
float calculate_directory_size(char *path) {
    struct stat st;
    float total_size = 0.0f;

    // Отримуємо інформацію про каталог
    if (stat(path, &st) != 0) {
        // Якщо сталася помилка при отриманні інформації про каталог, повертаємо 0
        return 0.0f;
    }

    // Якщо каталог є символьним посиланням, отримуємо інформацію про вказаний файл
    if (S_ISLNK(st.st_mode)) {
        if (stat(path, &st) != 0) {
            // Якщо сталася помилка при отриманні інформації про символьне посилання, повертаємо 0
            return 0.0f;
        }
    }

    // Якщо каталог - каталог, обчислюємо суму розмірів всіх файлів у ньому
    if (S_ISDIR(st.st_mode)) {
        DIR *dir;
        struct dirent *entry;

        // Відкриваємо каталог
        dir = opendir(path);
        if (dir == NULL) {
            return 0.0f;
        }

        // Читаємо каталог
        while ((entry = readdir(dir)) != NULL) {
            // Ігноруємо поточний каталог та батьківський каталог
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Формуємо повний шлях до файлу чи каталогу
            char full_path[PATH_MAX];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

            // Рекурсивно обчислюємо розмір файлу чи каталогу та додаємо його до загальної суми
            total_size += calculate_directory_size(full_path);
        }

        // Закриваємо каталог
        closedir(dir);
    }

    // Якщо каталог - регулярний файл, повертаємо його розмір
    if (S_ISREG(st.st_mode)) {
        return (float)st.st_size;
    }

    // Повертаємо загальний розмір каталогу
    return total_size;
}

char *format_file_size(float size) {
    static const char *suffixes[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    static const int num_suffixes = sizeof(suffixes) / sizeof(suffixes[0]);
    int i = 0;

    // Перевірка в межах величини суфіксів
    while (size >= 1024 && i < num_suffixes - 1) {
        size /= 1024;
        i++;
    }

    // Форматуємо число з двома цифрами після коми
    static char result[1000000]; // Достатньо для зберігання числа та суфікса
    sprintf(result, "%.2f %s", size, suffixes[i]);

    return result;
}
