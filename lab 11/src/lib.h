#ifndef SAMPLE_PROJECT_LIB_H 
#define SAMPLE_PROJECT_LIB_H

/**
 * @file lib.h
 * @author Tesliuk Vladyslav
 * @date 12-may-2024
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Максимальний розмір матриці */
#define MAX_SIZE 10 

void preview();
void readMatrix(double matrix[MAX_SIZE][MAX_SIZE], int size);
void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int size);
void inverseMatrix(double matrix[MAX_SIZE][MAX_SIZE], double inverse[MAX_SIZE][MAX_SIZE], int size);

#endif /* LIB_H */
