#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void initFileList(FileList* list) {
    list->size = 0;
    list->capacity = 10;
    list->files = (File*)malloc((size_t)list->capacity * sizeof(File));
}

void freeFileList(FileList* list) {
    free(list->files);
    list->files = NULL;
    list->size = 0;
    list->capacity = 0;
}

void addFile(FileList* list, File file) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->files = (File*)realloc(list->files, (size_t)list->capacity * sizeof(File));
    }
    list->files[list->size++] = file;
}

void removeFile(FileList* list, int index) {
    if (index < 0 || index >= list->size) {
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->files[i] = list->files[i + 1];
    }
    list->size--;
}

void printFileList(const FileList* list) {
    for (int i = 0; i < list->size; i++) {
        File file = list->files[i];
        printf("Hidden: %d, Name: %s, Size: %.2lf KB, Permissions: %d%d%d, Format: %s\n",
               file.hidden, file.name, file.size,
               file.permissions.read, file.permissions.write, file.permissions.execute,
               file.format);
    }
}

void filterFilesBySize(const FileList* list, double size, FileList* result) {
    initFileList(result);
    for (int i = 0; i < list->size; i++) {
        if (list->files[i].size > size) {
            addFile(result, list->files[i]);
        }
    }
}

void sortFileListByName(FileList* list) {
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = 0; j < list->size - i - 1; j++) {
            if (strcmp(list->files[j].name, list->files[j + 1].name) > 0) {
                File temp = list->files[j];
                list->files[j] = list->files[j + 1];
                list->files[j + 1] = temp;
            }
        }
    }
}