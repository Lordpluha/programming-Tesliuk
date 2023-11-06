#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * 25.(**) Визначити, чи є ціле 6-значне число “щасливим” квитком
 * (“щасливий квиток” – квиток, 15в  якому сума першої  половини  чисел  номера  дорівнює  сумі  другої  половини. 
 * Наприклад, білет  з номером  102300  є щасливим, бо  1 + 0 + 2  =  3 + 0 + 0.
 * Виковнав: Теслюк Владислав Андрiйович КН-923г
*/

#define TicketLength 6

int main() {
	// Инициализация переменных
	char ticketNumber;
	int firstPart = 0;
	int secondPart = 0;

	// Запрашиваем данные
	printf("Input your ticket':\n");;
	scanf("%s", &ticketNumber);

	// Разбиение char в массив char
	char * ticketArray = strtok(&ticketNumber, "");

	// Суммирование левых и правых цифр
	for (int i = 0; i < (TicketLength/2); i++) {
		char cur1 = ticketArray[i];
		int reveseI = TicketLength-i-1;
		char cur2 = ticketArray[reveseI];
		
		firstPart += atoi(&cur1);
		secondPart += atoi(&cur2);
	}
	
	// Вывод результатов
	if (firstPart == secondPart) {
		printf("Щасливий квиток");
	} else {
		printf("НЕЩасивий квиток");
	}

	return 0;
}