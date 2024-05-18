#include <stdio.h>
#include "list.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file path>\n", argv[0]);
        return 1;
    }

    const char* inputFile = argv[1];
    FileList fileList;
    initFileList(&fileList);

    FILE *file = fopen(inputFile, "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }

    while (!feof(file)) {
        File fileEntry;
        fscanf(file, "%d %s %lf %d %d %d %s", &fileEntry.hidden, fileEntry.name,
               &fileEntry.size, &fileEntry.permissions.read, 
               &fileEntry.permissions.write, &fileEntry.permissions.execute,
               fileEntry.format);
        addFile(&fileList, fileEntry);
    }
    fclose(file);

    printFileList(&fileList);

    printf("\nFiltered files (size > 50 KB):\n");
    FileList largeFiles;
    filterFilesBySize(&fileList, 50.0, &largeFiles);
    printFileList(&largeFiles);
    freeFileList(&largeFiles);

    sortFileListByName(&fileList);
    printf("\nSorted files by name:\n");
    printFileList(&fileList);

    printf("\nAdding new file:\n");
    File newFile = {0, "NewFile", 60.0, {1, 1, 1}, "txt"};
    addFile(&fileList, newFile);
    printFileList(&fileList);

    printf("\nRemoving file at index 2:\n");
    removeFile(&fileList, 2);
    printFileList(&fileList);

    freeFileList(&fileList);
    return 0;
}