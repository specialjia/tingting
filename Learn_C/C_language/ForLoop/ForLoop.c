#define _CRT_SECURE_NO_WARNINGS
#include "ForLoop.h"
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
 

#define SIZE 10
#define PAR 72

int sweetie() // for循环计数
{
	const int NUMBER = 22;
	int count = 1;
	for (count; count <= NUMBER; ++count)
	{
		printf("Be my Valentine!\n");
	}
}

int for_cube()  // for循环建一个立方表
{
	int num;
	printf("   n    n cube\n");
	for (num = 1; num <= 6; ++num)
	{
		printf("%5d %5d\n", num, num * num * num);

	}
}

int for_down()  // 递减运算符来递减计算器
{
	int secs;
	for (secs = 5; secs > 0; --secs)
	{
		printf("%d seconds!\n", secs);
	}
	printf(" We have ignition!\n");  //点火

}
int for_13s() // 计数器递增13
{
	int n = 2;
	for (n; n < 60; n = n + 13)
	{
		printf("%d\n", n);
	}
}

int for_char() //用字符代替数字计数
{
	char  ch;
	for (ch = 'A'; ch <= 'Z'; ++ch)
	{
		printf("The ASCII value for %c is %d.\n", ch,ch);
	}
}
int for_geo()  //欠款递增的量几何增长(10%)
{
	double debt;
	for (debt = 100; debt < 150; debt = debt * 1.1)
	{
		printf("Your debt is now $%.2f.\n", debt);
	}
}

int for_none() // 省略一个或者多个表达式,但是分号不能省略
{
	int ans, n;
	ans = 2;
	for (n = 3; ans <= 25;)//分号不可省略
	{
		ans = ans * n;
	}
	printf("n= %d; ans = %d", n, ans);
}
int for_show() // 只对第1个表达式求值一次或执行一次
{
	int num = 0;
	for (printf("Keep entering numbers!\n"); num != 6;)
	{
		scanf("%d", &num);
	}
	printf("That's the one I want!\n");

}

int for_zeno()  // zenor人名  求序列之和  1+1/2+1/4+1/8+...
{
	int t_ct;  //项计数
	double time, power_of_2;
	int limit;
	printf("Enter the number of terms you want: ");
	scanf("%d", &limit);
	for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; ++t_ct, power_of_2 *= 2.0)
	{
		time += 1.0 / power_of_2;
	}
	printf("time =  %f when terms = %d.\n", time, t_ct);

}

int scores() //循环处理数组
{
	int index, score[SIZE]; //size=10
	int sum = 0;
	float average;
	printf("Enter %d golf socres:\n", SIZE);
	for (index = 0; index < SIZE; ++index)
	{
		scanf("%d", &score[index]);  //读取十个分数
	}
	printf("The scores raed in are as follows:\n");
	for (index = 0; index < SIZE; ++index)
	{
		printf("%5d", score[index]); //验证输入
	}
	printf("\n");
	for (index = 0; index < SIZE; ++index)
	{
		sum += score[index]; // 求总和
	}
	average = (float)sum / SIZE; // 求平均数
	printf("Sum of scores = %d, average = %.2f\n", sum, average);
	printf("That's a handicap of %.0f.\n", average - PAR);

}

double power(double n, int p); // ANSI函数原型 函数声明
int pow1()  //计算数的整数幂
{
	 
	double x, xpow;
	int exp;  // 指数幂

	printf("Enter a number and the positive integer power to which\n");
	printf("the numbe will be raised. (Enter  q to quit)");
	while (2 == scanf("%lf %d", &x, &exp))
	{
		xpow = power(x, exp); // 函数调用
		printf("%.3g to the power %d is %5g\n", x, exp, xpow);  // 根据数值%g自动输出格式
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoyed this power trip-- bye!\n");
	return 0;
}
double power(double n, int p) // 函数定义
{
	double pow = 1;
	int i;
	for (i = 1; i <= p; ++i)
	{
		pow *= n;

	}
	return pow;  //返回pow的值
}


int islower_userdefine(char ch)
{
	char ch1;
	printf("%c\n", ch);

}