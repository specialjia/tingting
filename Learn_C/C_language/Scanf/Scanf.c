#define _CRT_SECURE_NO_WARNINGS
#include "Scanf.h"
#include <stdio.h>
#include <stdlib.h>


int input()  // 如何使用&
{
	int age;
	float assets;  //资产
	char pet[30];
	 
	printf("Enter your age, assets, and favorite pet.\n");
	scanf(" %d %f ", &age, &assets);
	scanf("%s", pet);  //字符数组不需要使用&
	printf("%d $%.2f %s\n", age, assets, pet);

}

int varwid()  //使用变宽输出字段
{
	unsigned width, precision; // 宽度 精准度
	int number = 256;
	double weight = 242.5;  // 重量

	printf("Enter a field width: \n");
	scanf("%d", &width);
	printf("The number is : %*d\n", width, number);
	printf("Now enter a width and a precision: \n");
	scanf("%d %d ", &width, &precision);
	printf("Weight = %*.*f\n", width, precision, weight);
	printf("Done!\n");

}

int SkipTwo()  // 跳过输入中的前两个整数
{
	int n;
	printf("Please enter three integers: \n");
	scanf("%*d %*d %d", &n);
	printf("The last integer was %d\n", n);


}
