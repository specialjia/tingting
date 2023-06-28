#define _CRT_SECURE_NO_WARNINGS
#include "Operator.h"
#include <stdio.h>
#include <stdlib.h>
#define SQUARES 64  // 棋盘中的方格数
#define SEC_PER_MIN 60  // 一分钟60秒

int golf()
{
	int jane, tarzan, cheeta;
	cheeta = tarzan = 68;
	jane = 54;
	printf("                   cheeta  tarzan    jane\n");
	printf("First round score %4d %8d %8d\n", cheeta, tarzan, jane);

}

int squares()
{
	int i = 1;
	for (i; i < 21; ++i)
	{
		printf("%4d %6d\n", i, i * i);
	}

	int num = 1;
	while (num < 21)
	{
		printf("%4d %6d\n", num, num * num);
			num = num + 1;

	}
	
}

int whear() //指数增长
{
	const double CROP = 2E16; // 世界小麦产谷粒数
	double current, total;
	int count = 1;

	printf("square   granins      total   ");
	printf("   fraction of \n");
	printf("         added        grains");
	printf("     world total\n");
	total = current = 1.0;  // 从一颗谷粒开始
	printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
	while (count < SQUARES)
	{
		count = count + 1;
		current = 2.0 * current;
		total = total + current;
		printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP); 
	}
	printf("That's all.\n");

}

int divide()  //除法
{
	printf("integer division:  5/4  is  %d\n", 5 / 4);
	printf("integer division:  6/3  is  %d\n", 6 / 3);
	printf("integer division:  7/4  is  %d\n", 7 / 4);
	printf("floating division:  7./4  is  %1.2f\n", 7. / 4);
	printf("mixed division:  7./4  is  %1.2f\n", 7. / 4);

}

int rules()  // 优先级测试
{
	int top, score;
	top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
	printf("top = %d, score = %d\n", top, score);
	/*
	 1.递增递减运算优先级仅低于圆括号
	
	
	*/

}

int MinSec()  //把秒数换成分和秒  (取余数%)
{

	int sec, min, left;
	printf("Convert seconds to minutes and seconds!\n"); //把秒数换成分和秒 
	printf("Enter the number of seconds (<=0 to quit): \n");
	scanf("%d", &sec); // 读取秒数
	while (sec > 0)
	{
		min = sec / SEC_PER_MIN;  // 截断分钟数
		left = sec % SEC_PER_MIN; // 剩下的秒数
		printf("%d seconds is %d minutes, %d seconds.\n", sec, min, left);
		printf("Enter next value (<=0 to quit):\n");
		scanf("%d", &sec);
	}
	printf("Done!\n");
	 
	// 如果第一个运算对象是负数,那么求模(取余数%)的结果为负数.第一是正数,结果也是正数
	// 两个负数,结果是正数

}
int AddOne() // 递增: 前缀 后缀
{
	int ultrai = 0;
	int super = 0;
	for (super = 0; super < 5; super++)
	{
		++ultrai;
		printf("super = %d, ultrai = %d\n", super,ultrai);
	}
	/* 运行结果
	super = 0, ultrai = 1
	super = 1, ultrai = 2
	super = 2, ultrai = 3
	super = 3, ultrai = 4
	super = 4, ultrai = 5
	*/
	

	int i = 0, j = 0;
	while (j < 5)
	{
		j++;
		++i;
		printf("i= %d,j = %d\n", i, j);

	}
	/*  运行结果
	i= 1,j = 1
	i= 2,j = 2
	i= 3,j = 3
	i= 4,j = 4
	i= 5,j = 5
	
	i++是先赋值，然后再自增；++i是先自增，后赋值。                                                                                                                                                                                                                                                                                                                                                                   
	用代码表示就是：
	若 a = i++; 则等价于 a=i;i=i+1;
	而 a = ++i; 则等价于 i=i+1;a=i;
	
	*/
}
 