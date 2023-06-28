#define _CRT_SECURE_NO_WARNINGS
#include "getchar.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>     //Ϊisspace() �����ṩԭ��
#include <stdbool.h>   // Ϊbool,true,false�ṩ����
#define SPACE ' '
#define PERIOD '.'
#define STOP '|'

int cypher()  //��������,�ո񲻱�
{
	char ch;
	ch = getchar();  //��ȡһ���ַ�
	while (ch != '\n')  // ��һ��δ����ʱ
	{
		if (ch == SPACE) //���¿ո�
			putchar(ch);  // ���ַ�����
		else
			putchar(ch + 1);  // �ı���ַ�
		ch = getchar(); // ��ȡ��һ���ַ�
	}
	putchar(ch); //��ӡ���з�

}

int cypher1()  //�滻�������ĸ,����ĸ�ַ���ֽ����
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))  // ���ʱһ���ַ�
			putchar(ch + 1); //��ʾ���ַ�����һ���ַ�
		else
			putchar(ch); // ԭ����ʾ
	}
	putchar(ch);

}  // ��Сд��ĸ�����滻��,���˿ո�ͱ�����



int chcount()  // ʹ���߼��������
{
	char ch;
	int charcount = 0;
	while (ch = getchar() != PERIOD)
	{
		if (ch != '"' && ch != '\'')  //����˫����Ҳ���ǵ�����
			++charcount;
	}
	printf("There are %d non-quote characters.\n", charcount);

	// 3���߼������ &&:��(and)   ||:��(or)   !:��(not)
}
/*
	���ȼ�: 
	!�����ȼ��ܸ�,�ȳ˷������,�������������ȼ���ͬ,ֻ��Բ���ŵ����ȼ���;
	&&��||���ȼ���,���߶��ȹ�ϵ�������,�ȸ�ֵ�������;
	a > b && b > c || b >d  �൱��  (a > b) && (b > c) || (b >d)

*/


int wordcnt()  // ͳ���ַ���,������,����
{
	char c;     // �����ַ�
	char prev;  //����ǰһ���ַ�
	long n_chars = 0L;  //�ַ���
	int n_lines = 0;   //����
	int n_words = 0;   //������
	int p_lines = 0;   //������������
	bool inword = false;  //���c�ڵ�����, inword����true

	printf("Plesae enter text to be analyzed ( | to terminate):\n");
	prev = '\n';    //����ʶ����������
	while ((c = getchar()) != STOP)
	{
		n_chars++;    //ͳ���ַ�
		if (c == '\n')
			n_lines++;  //ͳ������
		if (!isspace(c) && !inword)
		{
			inword = true;  // ��ʼһ���µĵ���
			n_words++;      // ͳ�Ƶ���
		}
		if (isspace(c) && inword)
			inword = false;  //���ﵥ�ʵ�ĩβ
		prev = c;            //�����ַ���ֵ
	}
	if (prev != '\n')
		p_lines++;
	printf("characters = %ld , words = %d, lines = %d\n", n_chars, n_words, n_lines);
	printf("partial lines = %d\n", p_lines);
}

int ecoh_eof()  // �ظ�����,ֱ���ļ���β
{
	int ch;
	while (EOF != (ch = getchar()))
	{
		putchar(ch);
	}
}

int file_eof()  // ��һ���ļ�����ʾ���ļ�
{
	int ch;
	FILE* fp;
	char fname[50];  // �洢�ļ���
	printf("Enter the name of the file: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");  // �򿪲���ȡ�ļ�
	if (fp == NULL);  // ���ʧ��
	{
		printf("Failed to open file. Bey\n");
		exit(1);  //�˳�����
	}
	// getc(fp)�Ӵ򿪵��ļ��л�ȡ��һ���ַ�
	while ((ch = getchar()) != EOF)
		putchar(ch);
	fclose(fp);  // �ر��ļ�
}