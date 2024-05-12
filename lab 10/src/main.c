/**
 * Зверніть увагу.  При  виконанні  завдання  ви  повинні  використовувати  динамічне  виділення пам’яті  для  масивів.
 * 14. (**)  Дано  масив  масивів  з  N   *  N   цілих  чисел.
 * Елементи  головної  діагоналі  записати  в одновимірний масив,
 * отриманий масив упорядкувати за  зростанням.
 */

#include "lib.h"

int main() {
    int N;
    printf("Введіть розмірність масиву N: ");
    scanf("%d", &N);

    // Виділення пам'яті для масиву масивів
    int **matrix = (int **)malloc((unsigned long)N * sizeof(int *));
    for (int i = 0; i < N; i++)
        matrix[i] = (int *)malloc((unsigned long)N * sizeof(int));

    // Зчитування елементів масиву масивів
    printf("Введіть елементи масиву масивів:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &matrix[i][j]);

    // Виділення пам'яті для одновимірного масиву головної діагоналі
    int *diagonal = (int *)malloc((unsigned long)N * sizeof(int));

    // Запис елементів головної діагоналі у одновимірний масив
    for (int i = 0; i < N; i++) 
        diagonal[i] = matrix[i][i];

    // Сортування одновимірного масиву за зростанням
    sort(diagonal, N);

    // Виведення відсортованого масиву
    printf("Відсортований масив головної діагоналі:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", diagonal[i]);
    }
    printf("\n");

    // Звільнення виділеної пам'яті
    free(diagonal);
    for (int i = 0; i < N; i++)
        free(matrix[i]);

    free(matrix);

    return 0;
}
