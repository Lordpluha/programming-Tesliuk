#include "list.h"

// Ініціалізація списку
void init_list(List *list) {
    list->head = NULL;
}

/// Вивід вмісту списку на екран
void print_list(const List *list) {
    Node *current = list->head;
    if (current == NULL) {
        printf("List is empty!");
        return;
    }
    while (current) {
        if (current->type == 1) {
            Violin *violin = (Violin *)&current->data;
            printf("Type: Violin, Acoustic: %d, Brand: %s, Year: %d, Bow Weight: %.2f, Bow Material: %s, Size: %s, has_bridge: %d, has_chinrest: %d, type: %s\n",
                   violin->base.is_acoustic, violin->base.brand, violin->base.year,
                   violin->base.bow.weight, violin->base.bow.material, violin->base.size,
                   violin->has_bridge, violin->has_chinrest, violin->type);
        } else if (current->type == 2) {
            DoubleBass *bass = (DoubleBass *)&current->data;
            printf("Type: DoubleBass, Acoustic: %d, Brand: %s, Year: %d, Bow Weight: %.2f, Bow Material: %s, Size: %s, has_extra_string: %d, endpin_length: %d\n",
                   bass->base.is_acoustic, bass->base.brand, bass->base.year,
                   bass->base.bow.weight, bass->base.bow.material, bass->base.size,
                   bass->has_extra_string, bass->endpin_length);
        } else {
            printf("Unknown entity to display!");
        }

        current = current->next;
    }
}

// Додавання скрипки до кінця списку
void append_violin(List *list, const Violin *violin) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        perror("Failed to append to list");
        return;
    }
    new_node->data = malloc(sizeof(Violin));
    if (!new_node->data) {
        perror("Failed to allocate data");
        free(new_node);
        return;
    }
    memcpy(&new_node->data, violin, sizeof(Violin));
    new_node->type = 1;
    new_node->next = NULL;

    if (!list->head) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    printf("Success!");
}

void append_doubleBass(List *list, const DoubleBass *bass) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        perror("Failed to append to list");
        return;
    }
    new_node->data = malloc(sizeof(DoubleBass));
    if (!new_node->data) {
        perror("Failed to allocate data");
        free(new_node);
        return;
    }
    memcpy(&new_node->data, bass, sizeof(DoubleBass));
    new_node->next = NULL;
    new_node->type = 2;

    if (!list->head) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    printf("Success!");
}

/// Видалення елемента зі списку за індексом
void delete_at_index(List *list, int index) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (index < 0) {
        printf("Invalid index.\n");
        return;
    }

    Node *current = list->head;
    Node *previous = NULL;

    // Якщо видаляється перший елемент списку
    if (index == 0) {
        list->head = current->next;
        free(current);
        return;
    }

    // Знаходимо попередній елемент перед елементом, який треба видалити
    for (int i = 0; current != NULL && i < index; ++i) {
        previous = current;
        current = current->next;
    }

    // Якщо current дорівнює NULL, індекс був за межами списку
    if (current == NULL) {
        printf("Index out of bounds.\n");
        return;
    }

    // Від'єднуємо вузол від списку
    previous->next = current->next;

    // Звільняємо пам'ять
    free(current);
}


// Допоміжна функція для злиття двох відсортованих списків
Node* merge(Node *left, Node *right, int (*compare)(const void *, const void *)) {
    if (!left) return right;
    if (!right) return left;

    Node *result = NULL;

    if (compare(&left->data, &right->data) <= 0) {
        result = left;
        result->next = merge(left->next, right, compare);
    } else {
        result = right;
        result->next = merge(left, right->next, compare);
    }

    return result;
}

// Розбиття списку на дві половини
void split_list(Node *source, Node **front, Node **back) {
    Node *fast = source->next;
    Node *slow = source;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// Сортування списку злиттям
void merge_sort(Node **head_ref, int (*compare)(const void *, const void *)) {
    if (!*head_ref || !(*head_ref)->next) {
        return;
    }

    Node *head = *head_ref;
    Node *left;
    Node *right;

    split_list(head, &left, &right);

    merge_sort(&left, compare);
    merge_sort(&right, compare);

    *head_ref = merge(left, right, compare);
}

// Функція для сортування списку за критерієм
void sort_list(List *list, int (*compare)(const void *, const void *)) {
    merge_sort(&list->head, compare);
}

/// Пошук найстарішої скрипки фірми Yamaha
Violin* find_oldest_yamaha_violin(const List *list) {
    Node *current = list->head;
    Violin *oldest = NULL;

    while (current) {
        printf("Output %d", current->type);
        if (current->type == 1) {
            Violin *violin = (Violin *)current->data;
            if (strcmp(violin->base.brand, "Yamaha") == 0) {
                if (!oldest || violin->base.year < oldest->base.year) {
                    oldest = violin;
                }
            }
        }
        current = current->next;
    }

    return oldest;
}
