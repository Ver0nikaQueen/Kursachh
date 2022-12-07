#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <string.h>
float formuls2(float n, int t)
{
	switch (t) {
	case 0:
		return 1.84523 * powf(n * 100 - 75, 1.348);
		break;
	case 1:
		return 0.188807 * powf(n * 100 - 210, 1.41);
		break;
	case 2:
		return 56.0211 * powf(n - 1.5, 1.05);
		break;
	case 3:
		return 15.9803 * powf(n - 3.8, 1.04);
		break;
	case 4:
		return 4.99087 * powf(42.5 - n, 1.81);
		break;
	case 5:
		return 9.23076 * powf(26.7 - n, 1.835);
		break;
	case 6:
		return 0.11193 * powf(254 - n, 1.88);
		break;
	default:
		return 0;
	}
}
int main()
{
	system("chcp 1251"); system("cls");	char a;
	printf("	Вас приветствует справочник по результатам XXII-ого семиборья по Воронежской области\n\n");
	char fname[] = "data.txt";
	FILE * in; float at;
	in = fopen(fname, "r");
	if (in == NULL)	{	printf("Ошибка открытия файла");	return 0;}
	static float rezg[50][50]; //float* arr = &rezg;
	int uchas = 3, vs = 7;// все отдельно
	for (int i = 0; i < vs; i++) {
		for (int j = 0; j < uchas; j++) {
			fscanf(in, "%f", &at);
			if (at == 00, 00) break;
			rezg[i][j] = at;
		}
	}
	fclose(in);
	//////////////////////////////
	char name[3][50] = { "Коваленко В.А.","Максимов К.Н.","Попов К. П." };
	char vidsport[7][50] = { "ПРЫЖКИ В ВЫСОТУ","ПРЫЖКИ В ДЛИНУ", "ТОЛКАНИЕ ЯДРА", "МЕТАНИЕ КОПЬЯ","БЕГ 200 МЕТРОВ", "БЕГ 100 МЕТРОВ С/Б", "БЕГ 800 МЕТРОВ" };


	do {
		char c;
		printf("Выберите интересующее действие: \n1 - Узнать результаты участника соревнований \n2 - Узнать результаты вида состязаний \n3 - Вывести итоговый рейтинг \n4 - Стереть результаты запросов \n->>>> ");
		scanf("%c", &c);
		getchar();
		switch (c)
		{
		case '1':
			printf("Введите номер участника\n"); int m = 0;
			scanf("%d", &m); getchar();
			//ucact(rezg,n); 
			printf("Запрос на участника: "); char razm = 'm'; printf("%s\n",name[m-1]);
			//if (m == 1) printf("Коваленко В.А.\n"); if (m == 2) printf("Максимов К.Н.\n"); if (m == 3) printf("Попов К. П.\n");//не забыть -1!
			printf("	Номер состязания	|	Результат	|   Набранные баллы	\n"); float r = 0,cumm=0; 
			printf("------------------------------------------------------------------------------\n");
			for (int i = 0; i < 7; i++)
			{	
				if (i > 3) razm='c';
				r = formuls2(rezg[i][m - 1], i); cumm += formuls2(rezg[i][m - 1], i);;
				if (i!=5) printf("	%s		|	%0.3f	%c	|	%0.3f	\n", vidsport[i], rezg[i][m - 1], razm, r);
				else printf("	%s	|	%0.3f	%c	|	%0.3f		\n", vidsport[i], rezg[i][m - 1], razm, r);
			}printf("\n");
			printf("Общая сумма очков участника соревнований: %0.3f\n\n",cumm);
			break;
		//в глазах сливаетсяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяя/////////
		case '2':
			printf("Введите номер вида спорта\n"); int m1 = 0; 
			scanf("%d", &m1); getchar(); printf("Запрос на вида спорта: "); m1--;
			switch (m1)
			{
			case 0:	printf("ПРЫЖКИ В ВЫСОТУ\n"); break;
			case 1:	printf("ПРЫЖКИ В ДЛИНУ\n"); break;
			case 2:	printf("ТОЛКАНИЕ ЯДРА\n"); break;
			case 3:	printf("МЕТАНИЕ КОПЬЯ\n"); break;
			case 4:	printf("БЕГ 200 МЕТРОВ\n"); break;
			case 5:	printf("БЕГ НА 100 МЕТРОВ С БАРЬЕРАМИ\n"); break;
			case 6:	printf("БЕГ 800 МЕТРОВ\n"); break;

			default: printf("ПРЫЖКИ СО СКАЛЫ\n"); break;
			}
			printf("	Участник	|	Результат	| Набранные баллы	|\n"); float r1 = 0, maxx = 0, ma11 = 0; 
			printf("-------------------------------------------------------------------------\n");
			if (m1 > 3) razm = 'c';
			else razm = 'm';
			
			for (int i = 0; i < uchas; i++)
			{
				r1 = formuls2(rezg[m1][i], m1); 
				if (formuls2(rezg[m1][i], m1) > maxx) {	maxx = formuls2(rezg[m1][i], m1); ma11 = i;}
				printf("	%s	|	%0.3f	%c	|	%0.3f		|\n", name[i], rezg[m1][i],razm, r1);
			}printf("\n");
			printf("Рекорд данного вида спорта принадлежит участнику %d, набравшему %0.3f баллов\n\n", 1,maxx); // косяк с номером участника
			break;
		case '3':
			printf("		Итоги забега\n");  
			printf("	Участник	|	Баллы	|	Место	|\n"); 
			printf("---------------------------------------------------------\n");
			float fin[20] = { 0 };
			for (int i = 0; i < uchas; i++)
			{
				for (int j = 0; j < vs;j++) fin[i] += formuls2(rezg[j][i],j);
			}
			//вычисление баллов



			for (int i = 0; i < uchas; i++)
			{	
				printf("	%s	|", name[i]);printf("	%.0f	|",fin[i]);
				printf("	%d	|",i+1);
				printf("\n");
			}printf("\n");//вввывод
			break;
			//в глазах сливаетсяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяя/////////
		case '4':
			system("cls"); break;
		default:
			printf("Некорректный ввод :^)\n"); break;
		}
		printf("Желаете продолжить? Да - 1, Нет - любой другой символ > ");
		scanf("%c", &a);
		getchar();
	} while (a == '1');
	printf("Программа выключена", a);

	return 0;
}