#include "lib.h"

void readFileData(const char* filename, File* files, int* count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    *count = 0;
    while (fscanf(file, "%d %s %lf %d %d %d %s", &files[*count].hidden, files[*count].name,
                  &files[*count].size, &files[*count].permissions.read, 
                  &files[*count].permissions.write, &files[*count].permissions.execute,
                  files[*count].format) != EOF) {
        (*count)++;
    }
    
    fclose(file);
}

void writeFileData(const char* filename, File* files, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %lf %d %d %d %s\n", files[i].hidden, files[i].name, files[i].size,
                files[i].permissions.read, files[i].permissions.write, files[i].permissions.execute,
                files[i].format);
    }
    
    fclose(file);
}

void printFileData(File* files, int count) {
    for (int i = 0; i < count; i++) {
        printf("Hidden: %d, Name: %s, Size: %.2lf KB, Permissions: %d%d%d, Format: %s\n",
               files[i].hidden, files[i].name, files[i].size,
               files[i].permissions.read, files[i].permissions.write, files[i].permissions.execute,
               files[i].format);
    }
}

void filterFilesBySize(File* files, int count, double size, File* result, int* resultCount) {
    *resultCount = 0;
    for (int i = 0; i < count; i++) {
        if (files[i].size > size) {
            result[*resultCount] = files[i];
            (*resultCount)++;
        }
    }
}

void sortFilesByName(File* files, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(files[j].name, files[j + 1].name) > 0) {
                swap(&files[j], &files[j + 1]);
            }
        }
    }
}

File* findSecondFileWithPermissions(File* files, int count) {
    sortFilesByName(files, count);
    int foundCount = 0;
    for (int i = 0; i < count; i++) {
        if (files[i].permissions.read && files[i].permissions.write && files[i].permissions.execute) {
            foundCount++;
            if (foundCount == 2) {
                return &files[i];
            }
        }
    }
    return NULL;
}

ImageFile* findImageWithLeastPixels(ImageFile* images, int count) {
    if (count == 0) return NULL;
    ImageFile* minImage = &images[0];
    int minPixels = images[0].width * images[0].height;
    for (int i = 1; i < count; i++) {
        int pixels = images[i].width * images[i].height;
        if (pixels < minPixels) {
            minImage = &images[i];
            minPixels = pixels;
        }
    }
    return minImage;
}

void swap(File* a, File* b) {
    File temp = *a;
    *a = *b;
    *b = temp;
}