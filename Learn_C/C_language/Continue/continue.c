#define _CRT_SECURE_NO_WARNINGS
#include "continue.h"
#include <stdio.h>
#include <stdlib.h>

int skippart()  // 使用continue 跳过部分循环
{
	const float MIN = 0.0f;
	const float MAX = 100.0f;
	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;   // 看不懂这两个定义
	float max = MIN;   //
	printf("Please enter the first score(q to quit): ");
	while (1 == scanf("%f", &score))
	{
		if (score < MIN || score > MAX)
		{
			printf("%0.1f is an invalid value. Try again:", score);
			continue;  //跳转至while循环的测试条件
		}
		printf("Accepting %0.1f: \n", score);
		min = (score < min) ? score : min;
		max = (score > max) ? score : max;
		total += score;
		++n;
		printf("Enter q to quit\n");
	}
	if (n > 0)
	{
		printf("Average of %d scores is %0.1f.\n", n, total / n);
		printf("Low = %0.1f, high = %0.1f\n", min, max);
	}
	else
		printf("No valid score were entered.\n");


}