#define _CRT_SECURE_NO_WARNINGS
#include "circulate.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ADJUST 7.31  //afjust调整校正


int shoes()  //计算多个不同鞋码对应的脚长
{
	const double SCALE = 0.333; //比例
	double shoe, foot;

	printf(" Shoe size (men's)     foot length\n");
	shoe = 3.0;
	while (shoe < 18.5)
	{
		foot = SCALE * shoe + ADJUST;
		printf("%10.1f %17.2f inches\n", shoe, foot);
		shoe = shoe + 1.0;
	}
	printf("If the shoe fits, wear it.\n");

}

int summing()  // 对用户输入得整数求和
{
	long num;
	long sum = 0L;
	int status;

	printf("Please enter an integer to be summed ");
	printf("(q to quit): ");
	status = scanf("%ld", &num);
	while (status == 1)
	{
		sum = sum + num;
		printf("Please enter next integer (q to quit): ");         
		status = scanf("%ld", &num);

	}
	printf("Those intefers sum to %ld. \n", sum);

}
int boolean()// s使用bool类型变量求输入整数的值
{
	long num;
	long sum = 0;
	_Bool input_is_good;

	printf("Please enter an integer to be summed");
	printf("(q to quit):");
	input_is_good = (1 == scanf("%ld", &num));
	while (input_is_good)
	{
		sum = sum + num;
		printf("Please enter next integer(q to quit): ");
		input_is_good = (1 == scanf("%ld", &num));
	}
	printf("Those integers sum to %ld.", sum);
}

int when() // 何时退出循环
{
	int n = 5;
	while (n < 7)
	{
		printf("n = %d\n", n);
		n++;
		printf("Now n = %d\n", n);
	}
	printf("The loop has finished.\n");

}

int cmpflt()  // compare 浮点数比较
{
	const double ANSWER = 3.14159;
	double response;
	printf("What is the value of pi?\n");
	scanf("%lf", &response);
	while (fabs(response - ANSWER) > 0.0001)  // fabs绝对值
	{
		printf("Try again!\n");
		scanf("%lf", &response);
	}
	printf("Close enough!\n");
}

int t_and_f() //C中的真和假
{
	int true_val, false_val;
	true_val = (10 > 2);
	false_val = (10 == 2);
	printf("true = %d; false = %d\n", true_val, false_val);

}

int truth()  // 哪些值为真 
{
	int n = 3;
	while (n)
	{
		printf("%2d is true\n", n--);
	}
	printf("%2d is false\n", n);

	n = -3;
	while (n)
	{
		printf("%2d is true\n", n++);
	}
	printf("%2d is false\n", n);
}

int sweetiel() // 一个奇数循环
{
	const int NUMBER = 22;
	int count = 1;
	while (count < NUMBER)
	{
		printf(" Be my valentine!\n");
		count++;

	}


}