#define _CRT_SECURE_NO_WARNINGS
#include "If else.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define RATE1 0.13230  // �״�ʹ��360kwh�ķ���
#define RATE2 0.15040  // ������ʹ��108kwh�ķ���
#define RATE3 0.30025  // ��ʹ��252KWH�ķ���
#define RATE4 0.34025  // ʹ�ó���720kwh�ķ���
#define BREAK1 360.0   // ���ʵĵ�һ���ֽ��
#define BREAK2 468.0   // ���ʵĵڶ����ֽ��
#define BREAK3 720.0   // ���ʵĵ������ֽ��
#define BASE1 (RATE1 * BREAK1) // ʹ��360kwh�ķ���
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1))) //ʹ��468kwh�ķ���
#define BASE3 (BASE2 + (RATE3 * (BREAK3 - BREAK2))  //ʹ��720kwh�ķ���

int electric()
{
	double kwh; // ʹ�õ�ǧ��ʱ
	double bill;  //���
	printf("Please enter the kwh used.\n");
	scanf("%lf", &kwh);
	if (kwh <= BREAK1)
		bill = RATE1 * kwh;
	else if (kwh <= BREAK2)  // 360~468 kwh
		bill = BASE1 + (RATE2 * (kwh - BREAK1));
	else if (kwh <= BREAK3)  // 468~720 kwh
		bill = BASE2 + (RATE3 * (kwh - BREAK2));
	else                     // ����720kwh
		bill = BASE3 + (RATE4 * (kwh - BREAK3)));
		printf("The charge for %.lf kwh is $%1.2lf.\n", kwh, bill);

}

int else1() //else��if�������
{
	int number = 0;
	printf("please enter a number: \n");
	scanf("%d", &number);
	if (number > 6)
		if (number < 12)
			printf("You are close!\n");
		else
			printf("Sorry, you lose a turn!\n");
	// ���û�л�����,else�����������ifƥ��

}

int divisors()  // ʹ��Ƕ�������ʾһ������Լ�� �ж��Ƿ�������
{
	unsigned long num = 0;  // �����Ե���
	unsigned long div;  //���ܵ�Լ��
	bool isprime;      // �����ı��

	printf("Please enter an integer for analysis; Enter q to quit.\n");
	while (1 == scanf("%lu", &num))
	{
		for (div = 2, isprime = true; (div * div) <= num; ++div)
		{
			if (0 == num % div)
			{
				if (div * div != num)
					printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
				else
					printf("%lu is divisible by %lu.\n", num, div);
				isprime = false;  // ������������
			}
		}
		if (isprime)
			printf("%lu is prime.\n", num);
		printf("please enter another integer for analysis; Enter q to quit.\n");
	}
	printf("Bye.\n");

}


