#define _CRT_SECURE_NO_WARNINGS
#include "If else.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define RATE1 0.13230  // 首次使用360kwh的费率
#define RATE2 0.15040  // 接着再使用108kwh的费率
#define RATE3 0.30025  // 再使用252KWH的费率
#define RATE4 0.34025  // 使用超过720kwh的费率
#define BREAK1 360.0   // 费率的第一个分界点
#define BREAK2 468.0   // 费率的第二个分界点
#define BREAK3 720.0   // 费率的第三个分界点
#define BASE1 (RATE1 * BREAK1) // 使用360kwh的费用
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1))) //使用468kwh的费用
#define BASE3 (BASE2 + (RATE3 * (BREAK3 - BREAK2))  //使用720kwh的费用

int electric()
{
	double kwh; // 使用的千瓦时
	double bill;  //电费
	printf("Please enter the kwh used.\n");
	scanf("%lf", &kwh);
	if (kwh <= BREAK1)
		bill = RATE1 * kwh;
	else if (kwh <= BREAK2)  // 360~468 kwh
		bill = BASE1 + (RATE2 * (kwh - BREAK1));
	else if (kwh <= BREAK3)  // 468~720 kwh
		bill = BASE2 + (RATE3 * (kwh - BREAK2));
	else                     // 超过720kwh
		bill = BASE3 + (RATE4 * (kwh - BREAK3)));
		printf("The charge for %.lf kwh is $%1.2lf.\n", kwh, bill);

}

int else1() //else与if配对问题
{
	int number = 0;
	printf("please enter a number: \n");
	scanf("%d", &number);
	if (number > 6)
		if (number < 12)
			printf("You are close!\n");
		else
			printf("Sorry, you lose a turn!\n");
	// 如果没有花括号,else与离它最近的if匹配

}

int divisors()  // 使用嵌套语句显示一个数的约数 判断是否是素数
{
	unsigned long num = 0;  // 待测试的数
	unsigned long div;  //可能的约数
	bool isprime;      // 素数的标记

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
				isprime = false;  // 该数不是素数
			}
		}
		if (isprime)
			printf("%lu is prime.\n", num);
		printf("please enter another integer for analysis; Enter q to quit.\n");
	}
	printf("Bye.\n");

}


