#define _CRT_SECURE_NO_WARNINGS
#include "comma.h"
#include <stdio.h>
#include<stdlib.h>

int postage()  // 一类邮资
{
	const int FIRST_OZ = 46;  //2013邮资 首重
	const int NEXT_OZ = 20;  // 2013邮资 续重
	int ounces, cost;  // 邮资为美分/盎司

	printf("ounces   cost\n");
	for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ++ounces, cost += NEXT_OZ)
	{
		printf(" %5d  $%4.2f\n", ounces, cost / 100.0);
	}
}

/*
 x = (y = 3, (z = ++y +2) +5) ,整个表达式的值是逗号右侧的值,即11

 h = 249,550 则输出结果是 h=249; 500;   249f赋值给h,500是表达式的值
 h = (249,500) 则 h=500; d逗号右侧的值
 逗号也可以做分隔符
 char ch,date;
 printf("%d %d \n", chimps,chumps)


*/