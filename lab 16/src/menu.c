#include "menu.h"

// Зчитування даних з файлу за допомогою fscanf
void read_from_file(const char *filename, List *list) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    int type;
    while (fscanf(file, "%d", &type) != EOF) {
        if (type == 1) {
            Violin violin;
            if (fscanf(file, "%d %49s %d %f %19s %3s %d %d %19s",
                       &violin.base.is_acoustic, violin.base.brand, &violin.base.year,
                       &violin.base.bow.weight, violin.base.bow.material, violin.base.size,
                       &violin.has_bridge, &violin.has_chinrest, violin.type) == 9) {
                append_violin(list, &violin);
            }
        } else if (type == 2) {
            DoubleBass bass;
            if (fscanf(file, "%d %49s %d %f %19s %3s %d %d",
                       &bass.base.is_acoustic, bass.base.brand, &bass.base.year,
                       &bass.base.bow.weight, bass.base.bow.material, bass.base.size,
                       &bass.has_extra_string, &bass.endpin_length) == 8) {
                append_doubleBass(list, &bass);
            }
        }
    }

    fclose(file);
}

// Функція для запису у файл
void write_to_file(const char *filename, const List *list) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Node *current = list->head;
    while (current) {
        if (current->type == 1) {
            Violin *violin = (Violin *)&current->data;
            fprintf(file, "%d %d %s %d %.2f %s %s %d %d %s\n",
                    1, violin->base.is_acoustic, violin->base.brand, violin->base.year,
                    violin->base.bow.weight, violin->base.bow.material, violin->base.size,
                    violin->has_bridge, violin->has_chinrest, violin->type);
        } else if (current->type == 2) {
            DoubleBass *bass = (DoubleBass *)&current->data;
            fprintf(file, "%d %d %s %d %.2f %s %s %d %d\n",
                    2, bass->base.is_acoustic, bass->base.brand, bass->base.year,
                    bass->base.bow.weight, bass->base.bow.material, bass->base.size,
                    bass->has_extra_string, bass->endpin_length);
        }
        current = current->next;
    }

    fclose(file);
}

/// Відображення меню
void display_menu(List *list) {
    int choice, index;
    Violin violin;
    Violin *oldest_violin;
    DoubleBass bass;
    char filename[256];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Read from file\n");
        printf("2. Write to file\n");
        printf("3. Display list\n");
        printf("4. Find oldest Yamaha violin\n");
        printf("5. Add entity\n");
        printf("6. Delete entity by index\n");
        printf("7. Sort list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                read_from_file(filename, list);
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);
                write_to_file(filename, list);
                break;
            case 3:
                print_list(list);
                break;
            case 4:
                oldest_violin = find_oldest_yamaha_violin(list);
                if (oldest_violin) {
                    printf("Oldest Yamaha Violin:\n");
                    printf("Year: %d\n", oldest_violin->base.year);
                } else {
                    printf("No Yamaha violin found.\n");
                }
                break;
            case 5:
                printf("Enter type of entity: \n = [1] - Violin (default)\n = [2] - DoubleBass\n");
                int type;
                scanf("%d", &type);
                if (type == 2) {
                    printf("Enter DoubleBass details (is_acoustic brand year bow_weight bow_material size has_extra_string endpin_length):\n");
                    scanf("%d %9s %d %f %19s %3s %d %d",
                        &bass.base.is_acoustic, bass.base.brand, &bass.base.year,
                        &bass.base.bow.weight, bass.base.bow.material, bass.base.size,
                        &bass.has_extra_string, &bass.endpin_length);
                    append_doubleBass(list, &bass);
                } else {
                    printf("Enter entity details (is_acoustic brand year bow_weight bow_material size has_bridge has_chinrest type):\n");
                    scanf("%d %9s %d %f %s %s %d %d %s",
                        &violin.base.is_acoustic, violin.base.brand, &violin.base.year,
                        &violin.base.bow.weight, violin.base.bow.material, violin.base.size,
                        &violin.has_bridge, &violin.has_chinrest, violin.type);
                    append_violin(list, &violin);
                }
                break;
            case 6:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                delete_at_index(list, index);
                break;
            case 7:
                // sort_list(list, compare_year);
                printf("List sorted by year.\n");
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
