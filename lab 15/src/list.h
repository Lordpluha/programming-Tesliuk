#ifndef LIST_H
#define LIST_H

#include "entity.h"

typedef struct {
    File* files;
    int size;
    int capacity;
} FileList;

void initFileList(FileList* list);
void freeFileList(FileList* list);
void addFile(FileList* list, File file);
void removeFile(FileList* list, int index);
void printFileList(const FileList* list);
void filterFilesBySize(const FileList* list, double size, FileList* result);
void sortFileListByName(FileList* list);

#endif // LIST_H