#define _CRT_SECURE_NO_WARNINGS
#include "Break.h"
#include <stdio.h>
#include <stdlib.h>

int break1()  // 使用break跳出循环
{
	float length, width;
	printf("Enter the length of the rectangle:\n");
	while (1 == scanf("%f", &length))
	{
		printf(" Length  = %0.2f:\n", length);
		printf("Enter its width:\n ");
		if (1 != scanf("%f", &width))
			break;
		printf("Width = %0.2f", width);
		printf("Area = %0.2f:\n", length * width);
		printf("Enter the length of the rectangle:\n");
	}
	printf("Done!.\n");


}