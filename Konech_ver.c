#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <string.h>
//#define vs   7
#define lEN 12
int ckolko();
int sortlr(float* mass, float* taz, int n);
float formuls2(float n, int t);
/*float rezults(int uc, float* rez[vs][lEN]) {
	float rez[50][50];
	char fname[] = "data2.txt";
	FILE* in; float at;
	in = fopen(fname, "r");
	if (in == NULL) { printf("������ �������� �����");	return 0; }
	for (int i = 0; i < vs; i++) {
		for (int j = 0; j < uc; j++) {
			fscanf(in, "%f", &rez[i][j]);
		}
	}
	fclose(in);
	return 1;
}*/
/*void wnam(char* name, int t) {
	FILE* mf; char str[40]; char* estr;
	//printf("�������� ����� : ");
	mf = fopen("1.txt", "r");
	if (mf == NULL) { printf("������\n"); return -1; }
	//else printf("���������\n");
	for (int i = 0; i < t; i++) {
		fscanf(mf, "%s ", &name[i]);
		printf("%s  ", name[i]);
		estr = fgets(str, sizeof(str), mf);
		if (estr == NULL) {
			if (feof(mf) != 0) {
				//printf("\n ������ ����� ���������\n");     
				break;
			}
			else { printf("\n ������ ������ �� �����\n");     break; }
		}
	}
	return name;
	fclose(mf);
}*/
int main()
{
	//float rez[vs][lEN];
	system("chcp 1251"); system("cls");
	char a; int uchas = ckolko(), vs = 7;
	printf("	��� ������������ ���������� �� ����������� XXII-��� ��������� �� ����������� �������\n\n");

	//rez = (float*)malloc(uchas * vs * sizeof(int));
	//rezults(uchas, i,rez);
	
	char fname[] = "data2.txt";
	FILE* in; float at;
	in = fopen(fname, "r");
	if (in == NULL) { printf("������ �������� �����");	return 0; }
	//
	float rezg[50][50];
	for (int i = 0; i < uchas; i++) {
		for (int j = 0; j < vs; j++) {
			fscanf(in, "%f", &at);
			if (at == 00, 00) break;
			rezg[i][j] = at;
		}
	}
	fclose(in);

	char name[12][30];
	FILE* mf; char str[40]; char* estr;
	//printf("�������� ����� : ");
	mf = fopen("1.txt", "r");
	if (mf == NULL) { printf("������\n"); return -1; }
	//else printf("���������\n");
	for (int i = 0; i < 12; i++) {
		fscanf(mf, "%s ", &name[i]);
		//printf("%s  ", name[i]);
		estr = fgets(str, sizeof(str), mf);
		if (estr == NULL) {
			if (feof(mf) != 0) {
				//printf("\n ������ ����� ���������\n");     
				break;
			}
			else { printf("\n ������ ������ �� �����\n");     break; }
		}
	}
	fclose(mf);

	char vidsport[7][50] = { "������ � ������","������ � �����", "�������� ����", "������� �����","��� 200 ������", "��� 100 ������ �/�", "��� 800 ������" };

	do {
		char c;// \n4 - �������� ������ ���������
		printf("�������� ������������ ��������: \n1 - ������ ���������� ��������� ������������ \n2 - ������ ���������� ���� ���������� \n3 - ������� �������� ������� \n5 - ������� ���������� �������� \n->>>> ");
		scanf("%c", &c);
		getchar();
		switch (c)
		{
		case '1':
			printf("������� ����� ���������\n"); int m = 0;
			scanf("%d", &m); getchar();

			printf("������ �� ���������: "); char razm = 'm'; printf("%s\n", name[m - 1]);
			printf("	����� ����������	|	���������	|   ��������� �����	\n"); float r = 0, cumm = 0;
			printf("------------------------------------------------------------------------------\n");
			for (int i = 0; i < 7; i++)
			{
				if (i > 3) razm = 'c';
				r = formuls2(rezg[m-1][i], i); cumm += formuls2(rezg[m-1][i], i);;
				if (i != 5) printf("	%s		|	%0.3f	%c	|	%0.3f	\n", vidsport[i], rezg[m-1][i], razm, r);
				else printf("	%s	|	%0.3f	%c	|	%0.3f		\n", vidsport[i], rezg[m-1][i], razm, r);
			}printf("\n");
			printf("����� ����� ����� ��������� ������������: %0.3f\n\n", cumm);
			break;

		case '2':
			printf("������� ����� ���� ������\n"); int m1 = 0;
			scanf("%d", &m1); getchar(); printf("������ �� ���� ������: "); m1--;
			printf("%s\n",vidsport[m1]);			
			printf("	��������	|	���������	| ��������� �����	|\n"); float r1 = 0, maxx = 0; int ma11 = 0; //��� �������
			float minn = 9999999; int ma12 = 99;
			printf("-------------------------------------------------------------------------\n");
			if (m1 > 3) razm = 'c';
			else razm = 'm';
			for (int i = 0; i < uchas; i++)
			{
				r1 = formuls2(rezg[i][m1], m1);
				if (r1 > maxx) { maxx =r1; ma11 = i; }
				if (r1 < minn) { minn = r1; ma12 = i; }
				printf("	%s	|	%0.3f	%c	|	%0.2f		|\n", name[i], rezg[i][m1], razm, r1);
			}printf("\n");
			printf("������ ������� ���� ������ ����������� ��������� ��� ������� %d - %s, ���������� %0.3f ������\n\n", ma11+1 ,name[ma11], maxx);
			printf("���������� ������� ���� ������ ����������� ��������� ��� ������� %d - %s, ���������� %0.3f ������\n\n", ma12 + 1, name[ma12], minn);
			break;
		case '3':
			printf("\n");
			printf("*** *** *** *** *** *** ����� ������ *** *** *** *** ***\n");
			printf("	��������	|	�����	|	�����	|\n");
			printf("---------------------------------------------------------\n");
			//���������� ������
			float* fin_b; int* fin;
			fin_b = (float*)malloc(uchas * sizeof(int));//����� ��� ������������ ������
			fin = (int*)malloc(uchas * sizeof(int));//������� ���������
			if (fin_b == NULL) { puts("error"); return -1; }
			if (fin == NULL) { puts("error"); return -1; }
			for (int i = 0; i < uchas; i++)
			{
				fin[i] = i;
				fin_b[i] = 0;
				for (int j = 0; j < vs; j++) {
					fin_b[i] += formuls2(rezg[i][j], j);
				}
			}
			sortlr(fin_b, fin, uchas);
			for (int i = 0; i < uchas; i++) { printf("	%s	|", name[fin[i]]); 	printf("	%.0f	|", fin_b[i]); printf("	%d	|", i + 1); printf("\n"); }//�������
			printf("---------------------------------------------------------\n");
			//�������
			char ab;
			do {
				char c;
				printf("���� ������� ������: \n1 - ����� ���������� �����, 2 - ������� ���������� �����, \n3 - ����������� � ������������  ���������� �����, 4 - ������\n>>> ");
				scanf("%c", &c);
				getchar(); float cum = 0, mint=99999, maxt=0;
				switch (c)
				{
				case '1':
					for (int i = 0; i < uchas; i++) cum += fin_b[i]; 
					printf("����� ���������� �����, ��������� ����������� ������������ - %0.3f ������\n",cum);
					break;
				case '2':
					for (int i = 0; i < uchas; i++) cum += fin_b[i]; 
					printf("������� ���������� �����, ��������� ����������� ������������ - %0.3f ������\n",cum/uchas); break;
				case '3':
					for (int i = 0; i < uchas; i++) mint = min(mint, fin_b[i]); 
					for (int i = 0; i < uchas; i++) maxt = max(maxt, fin_b[i]); 
					printf("������������ � ����������� ���������� �����, ��������� ����������� ������������ - %0.3f � %0.3f ������\n", maxt, mint); break;
				case '4':
					printf("�� � ����������!\n"); break;
				default:
					printf("������������ ���� :^)\n"); break;
				}
				printf("������� ����������? �� - 1, ��� - 0 > ");
				scanf("%c", &ab);
				getchar();
			} while (ab == '1');
			return 0;
			free(fin_b); free(fin);
			break;
		case '4':
			printf("������� ������� ���������\n"); char fam[20];
			scanf("%s", &fam[20]);
			FILE* out;
			if ((out = fopen("12.txt", "a")) == NULL) {
				printf("������ �������� �����  ��� ������");
				return 0;
			}
			fprintf(out, "%s \n", fam[20]);
			fclose(out);
			printf("������� ��������\n"); float rf;
			scanf("%f", &rf);
			FILE* out1;
			if ((out1 = fopen("12.txt", "a+")) == NULL) {
				printf("������ �������� �����  ��� ������");
				return 0;
			}
			fprintf(out1, "%0.3f \n", rf);
			fclose(out1);
			return 1;
			break;
		case '5':
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
int ckolko() {
	FILE* mf;  char str[60];  char* estr;
	//printf("�������� ����� : ");
	mf = fopen("1.txt", "r");
	if (mf == NULL) { printf("������\n"); return -1; }
	//else printf("���������\n");
	int vs1 = 0;
	while (1) {
		estr = fgets(str, sizeof(str), mf);
		if (estr == NULL) {
			if (feof(mf) != 0) {
				//printf("\n ������ ����� ���������\n");     
				break;
			}
			else { printf("\n ������ ������ �� �����\n");     break; }
		}
		vs1++;
	}
	//printf("�������� ����� : ");
	if (fclose(mf) == EOF) printf("������\n");
	//else printf("���������\n");
	return vs1;
}
int sortlr(float* mass, float* taz, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		int noSwap = 1; float tmp, tmp2;
		for (int j = 0; j < i; j++)
		{
			if (mass[j] < mass[j + 1])
			{
				tmp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp;
				tmp2 = taz[j];
				taz[j] = taz[j + 1];
				taz[j + 1] = tmp2;
				noSwap = 0;
			}
		}
		if (noSwap == 1)
			break;
	}
}
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