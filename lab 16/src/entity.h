#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Смичек
typedef struct {
    float weight; // Вага смичка у грамах
    char material[20]; // Матеріал деревка (бразильське дерево, пернамбуку, скловолокно)
} Bow;

// Iнструмент
typedef struct {
    int is_acoustic; // Чи акустичний
    char brand[50]; // Фірма/Майстер
    int year; // Рік створення
    Bow bow; // Смичок
    char size[4]; // Розмір (1, ½, ¼, ¾)
} Entity;

// Скрипка
typedef struct {
    Entity base; // Базовий клас
    int has_bridge; // Чи мае мiст
    int has_chinrest; // Чи мае пiдборiдник
    char type[20]; // Тип інструменту (сольний, оркестровий, універсальний)
} Violin;

// Контрабас
typedef struct {
    Entity base; // Базовий клас
    int has_extra_string; // Чи мае додаткову струну
    int endpin_length; // Довжина шпилю у см
} DoubleBass;

#endif // ENTITY_H