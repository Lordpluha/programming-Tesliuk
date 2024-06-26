# Лабораторна робота  №14.  Структуровані типи даних
## Загальне  завдання
> з  розділу  “Індивідуальні  завдання  комплексної роботи”  взяти  прикладну  галузь  стосовно номеру варіанту за  попередньо-визначеною формулою
> створити структуру, що  відображає “базовий клас” Структура директорії для  лабораторної роботи
<pre>
   └──lab15
      ├──Doxyfile
      ├──Makefile
      ├──README.md
      ├──assets
      │     └──input.txt
      ├──doc
      |   ├──assets
      |   |     ├──*.png
      │   |     └──lab15.drawio │ 
      |   └──lab15.md                          
      └──src
         ├── lib.c
         ├── lib.h
         └── main.c
</pre>

> Зверніть   увагу.       Вхідні   дані   розташовані   у   файлі   assets/input.txt.       Програма   повинна прийняти у якості  аргументу шлях до цього файлу (як і  у попередній роботі).
> Зверніть  увагу.   Очікується,  що  при  запуску  програми  з  параметрами  командної  строки, нічого від  користувача не  буде  очікуватись.
> Зверніть  увагу.  Передача  об’єктів  структури  в  функцію  (та  отримання  результатів  роботи функції, що  є  об’єкт типу  структури) обов’язково повинні передаватися “за  вказівником”.
## Індивідуальні  завдання.
### Обов’язкові завдання
 - розробити функцію,  яка читає дані  (масив елементів)  з  файлу;
 - розробити функцію,  яка записує дані (масив елементів)  у файл;
 - розробити функцію,  яка виводить масив елементів  на  екран;
 - реалізувати функцію №1 з категорії “Методи для роботи з колекцією”, на вхід якої потрапляє масив об’єктів. Слід звернути увагу, що усі необхідні дані повинні бути передані як аргументи функції. Наприклад, якщо треба знайти всі машини марки “Форд”, то функція потрібна мати аргумент “марка машини”, та у main() викликати цю функцію з потрібним значенням марки.
 - розробити функцію,  яка буде сортувати масив елементів  за  заданим критерієм  (полем);

## 01. Файл
### Поля базового класу:
 - Прихований файл  (наприклад:  так,  ні)
 - Назва файлу (наприклад:  “Лаба01”)
 - Розмір файлу, Кб (наприклад:  10,  123.56)
 - Доступи  (https://www.tutorialspoint.com/unix/unix-file-permission.htm)  (структура,  що даватиме можливість вказати можливість читання,  запису,  виконання)
 - Формат файлу  (один з  переліку:  txt,  docx, pdf,  mp3,  avi,  mp4,  mkv,  exe,  bat,  jar)
#### Спадкоємець 1 -  Відеофайл.  Додаткові поля:
 - Роздільна здатність (https://animoto.com/blog/news/hd-video-creation-sharing) (один з переліку:  360, 480, 720, 1080)
 - Частота  кадрів (https://uk.wikipedia.org/wiki/Частота_кадрів) (наприклад:  24,  72)
#### Спадкоємець 2 -  Файл зображення.  Додаткові поля:
 - Розмір зображення (структура, що має значення кількості пікселей по ширині та по висоті)
 - Кількість точок на дюйм (https://en.wikipedia.org/wiki/Dots_per_inch) (наприклад:  200, 300)
#### Методи для  роботи з  колекцією:
1. Обрати з  каталогу  всі файли більше 50 кБ
2. Відсортувати за  назвою та обрати другий файл,  що матиме всі доступи (rxw)
3. Знайти зображення, що  має найменшу кількість пікселів
