#define _CRT_SECURE_NO_WARNINGS
#include "Strlen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRAISE "You are an extraordinady being." // ����һ���� PRAISE
 
int Str()
{
	char name[40];
	printf("What's your name? ");
	scanf("%s", name);  //name����һ���ַ����ĵ�ַ,�������ȡ��ַ��&
	printf("Hello, %s.%s\n", name, PRAISE); //PRAISE��һ���ַ���
	printf("Your name of %zd letters occupies %zd memory cells.\n", strlen(name), sizeof(name));
	printf("The phrase of praise has %zd letters", strlen(PRAISE));
	printf("and occupies %zd memory cells.\n", sizeof(PRAISE));

}

int sizeof1()
{
	int n = 0;
	size_t intsize;
	intsize = sizeof(int);
	printf("n= %d, n has %zd bytes; all ints have %zd bytes.\n",n,sizeof(n) ,intsize);

}