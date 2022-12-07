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
	printf("	��� ������������ ���������� �� ����������� XXII-��� ��������� �� ����������� �������\n\n");
	char fname[] = "data.txt";
	FILE * in; float at;
	in = fopen(fname, "r");
	if (in == NULL)	{	printf("������ �������� �����");	return 0;}
	static float rezg[50][50]; //float* arr = &rezg;
	int uchas = 3, vs = 7;// ��� ��������
	for (int i = 0; i < vs; i++) {
		for (int j = 0; j < uchas; j++) {
			fscanf(in, "%f", &at);
			if (at == 00, 00) break;
			rezg[i][j] = at;
		}
	}
	fclose(in);
	//////////////////////////////
	char name[3][50] = { "��������� �.�.","�������� �.�.","����� �. �." };
	char vidsport[7][50] = { "������ � ������","������ � �����", "�������� ����", "������� �����","��� 200 ������", "��� 100 ������ �/�", "��� 800 ������" };


	do {
		char c;
		printf("�������� ������������ ��������: \n1 - ������ ���������� ��������� ������������ \n2 - ������ ���������� ���� ���������� \n3 - ������� �������� ������� \n4 - ������� ���������� �������� \n->>>> ");
		scanf("%c", &c);
		getchar();
		switch (c)
		{
		case '1':
			printf("������� ����� ���������\n"); int m = 0;
			scanf("%d", &m); getchar();
			//ucact(rezg,n); 
			printf("������ �� ���������: "); char razm = 'm'; printf("%s\n",name[m-1]);
			//if (m == 1) printf("��������� �.�.\n"); if (m == 2) printf("�������� �.�.\n"); if (m == 3) printf("����� �. �.\n");//�� ������ -1!
			printf("	����� ����������	|	���������	|   ��������� �����	\n"); float r = 0,cumm=0; 
			printf("------------------------------------------------------------------------------\n");
			for (int i = 0; i < 7; i++)
			{	
				if (i > 3) razm='c';
				r = formuls2(rezg[i][m - 1], i); cumm += formuls2(rezg[i][m - 1], i);;
				if (i!=5) printf("	%s		|	%0.3f	%c	|	%0.3f	\n", vidsport[i], rezg[i][m - 1], razm, r);
				else printf("	%s	|	%0.3f	%c	|	%0.3f		\n", vidsport[i], rezg[i][m - 1], razm, r);
			}printf("\n");
			printf("����� ����� ����� ��������� ������������: %0.3f\n\n",cumm);
			break;
		//� ������ ������������������������������������������������/////////
		case '2':
			printf("������� ����� ���� ������\n"); int m1 = 0; 
			scanf("%d", &m1); getchar(); printf("������ �� ���� ������: "); m1--;
			switch (m1)
			{
			case 0:	printf("������ � ������\n"); break;
			case 1:	printf("������ � �����\n"); break;
			case 2:	printf("�������� ����\n"); break;
			case 3:	printf("������� �����\n"); break;
			case 4:	printf("��� 200 ������\n"); break;
			case 5:	printf("��� �� 100 ������ � ���������\n"); break;
			case 6:	printf("��� 800 ������\n"); break;

			default: printf("������ �� �����\n"); break;
			}
			printf("	��������	|	���������	| ��������� �����	|\n"); float r1 = 0, maxx = 0, ma11 = 0; 
			printf("-------------------------------------------------------------------------\n");
			if (m1 > 3) razm = 'c';
			else razm = 'm';
			
			for (int i = 0; i < uchas; i++)
			{
				r1 = formuls2(rezg[m1][i], m1); 
				if (formuls2(rezg[m1][i], m1) > maxx) {	maxx = formuls2(rezg[m1][i], m1); ma11 = i;}
				printf("	%s	|	%0.3f	%c	|	%0.3f		|\n", name[i], rezg[m1][i],razm, r1);
			}printf("\n");
			printf("������ ������� ���� ������ ����������� ��������� %d, ���������� %0.3f ������\n\n", 1,maxx); // ����� � ������� ���������
			break;
		case '3':
			printf("		����� ������\n");  
			printf("	��������	|	�����	|	�����	|\n"); 
			printf("---------------------------------------------------------\n");
			float fin[20] = { 0 };
			for (int i = 0; i < uchas; i++)
			{
				for (int j = 0; j < vs;j++) fin[i] += formuls2(rezg[j][i],j);
			}
			//���������� ������



			for (int i = 0; i < uchas; i++)
			{	
				printf("	%s	|", name[i]);printf("	%.0f	|",fin[i]);
				printf("	%d	|",i+1);
				printf("\n");
			}printf("\n");//�������
			break;
			//� ������ ������������������������������������������������/////////
		case '4':
			system("cls"); break;
		default:
			printf("������������ ���� :^)\n"); break;
		}
		printf("������� ����������? �� - 1, ��� - ����� ������ ������ > ");
		scanf("%c", &a);
		getchar();
	} while (a == '1');
	printf("��������� ���������", a);

	return 0;
}