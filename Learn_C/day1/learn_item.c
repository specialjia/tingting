#define _CRT_SECURE_NO_WARNINGS
#include "learn_item.h"
#include <stdio.h>
void learn_if_else()
{
	float score = 0.0;
	float score1 = 0.0;
	printf("请输入您的分数:\n");

	int ret = scanf("%f%f", &score, &score1);
	printf("sancf ret:%d\n", ret);


	if (score > 100)
	{
		printf("这是做梦!\n");
	}
	else if (score >= 90 && score <= 100)
		printf("优秀!\n");
	else if (score >= 80 && score < 90)
		printf("良好!\n");
	else if (score >= 60 && score < 80)
		printf("及格!\n");
	else if (score >= 0 && score < 60)
		printf("不及格!继续努力!\n");
	else
		printf("输入的分数过低,请不要自卑!继续努力!\n");

}