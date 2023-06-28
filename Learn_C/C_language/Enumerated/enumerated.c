#define _CRT_SECURE_NO_WARNINGS
#include "enumerate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LEN 30


enum spectrum { red, orange, yellow, green, blue, violet };
const char* colors[] = { "red","orange","yellow","green","blue","voilet" };
char* s_gets_e(char* st, int n);
int enum1()  // ʹ��ö�����͵�ֵ
{
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;
	puts("Enter a color (empty line to quit):");
	while (s_gets_e(choice, LEN) != NULL && choice[0] != '\0')
	{
		for (color = red; color <= violet; ++color)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
			switch (color)
			{
			case red: puts("Roses are red.");
				break;
			case orange: puts("Poppies ar orange.");
				break;
			case yellow: puts("Sunflowers are yellow.");
				break;
			case green: puts("Grass is green.");
				break;
			case blue: puts("Bluebells are blue.");
				break;
			case violet: puts("Violents are violet.");
				break;
			}
		else
			printf("I don't know about the color %s .\n", choice);
		color_is_found = false;
		puts("Next color,please (empty line to quit):");
	}
	puts("Bey.");
}
char *s_gets_e(char* st, int n)
{
	char *ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');   //���һ��з�
		if (find)         //�����ַ���ǿ�
			*find = '\0';   // �ڴ˴�����һ�����ַ�
		else
			while (getchar() != '\n')
				continue;   //����������
	}
	return ret_val;
}

