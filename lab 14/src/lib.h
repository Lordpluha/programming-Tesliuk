#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для доступів
typedef struct {
    int read;
    int write;
    int execute;
} Permissions;

// Базова структура для файлу
typedef struct {
    int hidden;
    char name[50];
    double size; // у КБ
    Permissions permissions;
    char format[10];
} File;

// Спадкоємець 1 - Відеофайл
typedef struct {
    File base;
    int resolution;
    int frameRate;
} VideoFile;

// Спадкоємець 2 - Файл зображення
typedef struct {
    File base;
    int width;
    int height;
    int dpi;
} ImageFile;

// Функції для роботи з базовою структурою
void readFileData(const char* filename, File* files, int* count);
void writeFileData(const char* filename, File* files, int count);
void printFileData(File* files, int count);
void filterFilesBySize(File* files, int count, double size, File* result, int* resultCount);
void sortFilesByName(File* files, int count);
File* findSecondFileWithPermissions(File* files, int count);
ImageFile* findImageWithLeastPixels(ImageFile* images, int count);

// Допоміжні функції
void swap(File* a, File* b);

#endif
