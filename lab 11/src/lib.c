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
    printf("Лабораторна робота №11. Взаємодія з користувачем\n");
    printf("Автор: Теслюк Владислав Андрiйович\n");
    printf("Тема: Взаємодія з користувачем шляхом механізму введення/виведення\n");
}

/**
 * @brief Функція для зчитування матриці зі стандартного вводу
 * @param matrix змiнна для запису матрицi
 * @param size розмiр матрицi
 */
void readMatrix(double matrix[MAX_SIZE][MAX_SIZE], int size) {
    printf("Введіть елементи матриці %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

/**
 * @brief Функція для виведення матриці на екран
 * @param matrix змiнна матрицi для виводу
 * @param size розмiр матрицi
 */
void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int size) {
    printf("Матриця %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        printf("[ ");
        for (int j = 0; j < size; j++) {
            printf("%9.2f ", matrix[i][j]);
        }
        printf("]\n");
    }
}

/**
 * @brief Функція для обчислення детермінанту квадратної матриці
 * @param matrix змiнна матрицi для обчислення
 * @param size розмiр матрицi
 */
double determinant(double matrix[][10], int size) {
    double det = 0;
    double submatrix[MAX_SIZE][MAX_SIZE];

    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    } else {
        for (int x = 0; x < size; x++) {
            int subi = 0;
            for (int i = 1; i < size; i++) {
                int subj = 0;
                for (int j = 0; j < size; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (matrix[0][x] * determinant(submatrix, size - 1) * (x % 2 == 0 ? 1 : -1));
        }
    }
    return det;
}

/**
 * @brief Функція для знаходження транспонованої матриці
 * @param matrix змiнна матрицi для транспонування
 * @param transpose змiнна для запису транспонованої матрицi
 * @param size розмiр матрицi
 */
void transpose(double matrix[][10], double transpose[][10], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

/**
 * @brief Функція для знаходження зворотної матриці
 * @param matrix змiнна матрицi для обчислення оберненої
 * @param inverse змiнна для запису оберненої матрицi
 * @param size розмiр матрицi
 */
void inverseMatrix(double matrix[MAX_SIZE][MAX_SIZE], double inverse[MAX_SIZE][MAX_SIZE], int size) {
    double det = determinant(matrix, size);

    if (fabs(det-0) < M_E) {
        printf("Детермінант дорівнює нулю. Обернена матриця не існує.\n");
        return;
    }

    double transpose_matrix[10][10];
    transpose(matrix, transpose_matrix, size);

    // Обчислення алгебраїчних доповнень
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double submatrix[10][10];
            int subi = 0, subj = 0;
            for (int k = 0; k < size; k++) {
                if (k == i)
                    continue;
                subj = 0;
                for (int l = 0; l < size; l++) {
                    if (l == j)
                        continue;
                    submatrix[subi][subj] = transpose_matrix[k][l];
                    subj++;
                }
                subi++;
            }
            inverse[j][i] = determinant(submatrix, size - 1) * ((i + j) % 2 == 0 ? 1 : -1);
        }
    }

    // Обчислення оберненої матриці
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inverse[i][j] /= det;
        }
    }

    printMatrix(inverse, size);
}
