#ifndef LIST_H
#define LIST_H

#include "entity.h"
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct Node {
    Entity *data;
    int type; // 1 - Vialon, 2 - DoubleBass
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

/**
 * @brief Ініціалізація списку.
 * @param list Вказівник на список.
 */
void init_list(List *list);
void print_list(const List* list);
void append_violin(List *list, const Violin *violin);
void append_doubleBass(List *list, const DoubleBass *bass);
void sort_list(List *list, int (*compare)(const void *, const void *));
void delete_at_index(List *list, int index);

Violin* find_oldest_yamaha_violin(const List *list);

#endif