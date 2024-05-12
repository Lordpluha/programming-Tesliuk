#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

/**
 * @file lib.h
 * @author Tesliuk Vladyslav
 * @date 12-may-2024
 * @version 1.0.0
 */

void preview();
void read_from_file(FILE *f, char *result, int buf_size);
void write_to_file(FILE *f, char *data);
float calculate_directory_size(char *path);
char *format_file_size(float size);

#endif
