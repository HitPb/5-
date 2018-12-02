#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
char* workString(char* strochka);
char* EnterString();
int printmenu();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char *stroka = NULL;

	int punkt = 0;
	int rig = 0;

	do
	{
		punkt = printmenu();
		switch (punkt)
		{
		case 1:
		{
			stroka = EnterString();
			rig = 1;
		}
		break;
		case 2:
			if (rig != 1)
			{
				printf_s("Массив еще не введен\n");
				continue;
			}

			stroka = workString(stroka);

			rig = 1;
			break;
		case 3:
			if (rig != 1)
			{
				printf_s("Массив еще не введен\n");
				continue;
			}
			printf("%s\n", stroka);
		}
	} while (punkt != 4);


	delete[] stroka;
	return 0;

}
char* workString(char* strochka)
{
	int len = strlen(strochka);
	int k_point = 0;
	for (int i = 0; i < len; i++)
	{
		if (strochka[i] == '.' || strochka[i] == '...' || strochka[i] == '!' || strochka[i] == '?')
			k_point++;
	}
	printf("Количество предложений: %d\n", k_point);

	int i_max = 0;
	int k_letter = 0;
	int maxk_letter = 0;

	for (int i = 0; i < len; i++)
	{
		k_letter++;

		if (strochka[i] == '.' || strochka[i] == '...' || strochka[i] == '!' || strochka[i] == '?')
		{
			if ((k_letter > maxk_letter))
			{
				maxk_letter = k_letter;
				i_max = i;

			}
			k_letter = 0;
		}
	}
	printf("Cамое длинное предложение: ");
	for (int i = i_max - (maxk_letter - 1); i < i_max + 1; i++)
		printf("%c", strochka[i]);
	printf("\n");
	return strochka;
}
char* EnterString()
{
	int size = 0;
	printf("Введите строку: ");
	char* resultStr = new char[1];
	resultStr[0] = '\0';
	int ch = 0;
	while (ch != '\n')
	{
		ch = getchar();
		printf("%c", ch);
		size = strlen(resultStr);
		char* string = new char[size + 2];
		strcpy(string, resultStr);
		string[size] = ch;
		string[size + 1] = '\0';
		delete[] resultStr;
		resultStr = string;
		if ((ch == 8) && size >= 0)
		{
			system("cls");
			resultStr[size] = '\0';
			printf("%s", resultStr);
			size--;
		}
	}
	return resultStr;
}
int printmenu()
{


	char qwert = 0;

	printf("|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
	printf("|1)Ввод строки                           |\n");
	printf("|2)Обработка строки                      |\n");
	printf("|3)Выврд строки                          |\n");
	printf("|----------------------------------------|\n");
	printf("|4.выход                                 |\n");
	printf("|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n");

	int mops;

	while ((scanf_s("%d%c", &mops, &qwert, 1) != 2) || (qwert != '\n') || mops < 1 || mops>4)
	{
		printf("Вы не выбрали ни одного пункта меню\n");

		while (getchar() != '\n');

	}

	return mops;
}
