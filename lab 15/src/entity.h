#ifndef ENTITY_H
#define ENTITY_H

typedef struct {
    int hidden;
    char name[50];
    double size; // у КБ
    struct {
        int read;
        int write;
        int execute;
    } permissions;
    char format[10];
} File;

typedef struct {
    File base;
    int resolution;
    int frameRate;
} VideoFile;

typedef struct {
    File base;
    int width;
    int height;
    int dpi;
} ImageFile;

#endif // ENTITY_H