#define _CRT_SECURE_NO_WARNINGS
#include "运算符.h"
#include <stdio.h>
#include <stdlib.h>
#define COVERAGE 350  //每罐油漆可刷的面积(单位:平方英尺)

int paint()  // 使用条件运算符:?
{
	int sq_feet;
	int cans;
	printf("Enter number of square to be painted: \n");
	while (1 == scanf("%d", &sq_feet))
	{
		cans = sq_feet / COVERAGE;
		cans += (sq_feet % COVERAGE == 0) ? 0 : 1; // sq能否整数COVERAGE  可以的化值为0 ,不可以值则是1
		printf("You need %d %s of paint.\n", cans, cans = 1 ? "can" : "cans");
		printf("Enter next value(q to quit) :");
	}
}
// 运算结果不对