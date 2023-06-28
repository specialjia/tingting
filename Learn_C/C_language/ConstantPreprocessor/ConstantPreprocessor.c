#define _CRT_SECURE_NO_WARNINGS
#include "ConstantPreprocessor.h"
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159  //定义声明 一个宏  下面的程序遇到PI均被替换成常量 3.14159

int ConstantPreprocessor()
{
	float area, circum = 0, radius;
	printf("What is the radius of your pizza?\n");
	scanf("%f", &radius);
	area = PI * radius * radius;
	circum = PI * 2 * radius;
	printf(" Your basic pizza parameters are as follows:\n");
	printf("circumference = %1.2f, area = %1.2f\n", circum, area);  //圆的周长及面积的计算结果



}