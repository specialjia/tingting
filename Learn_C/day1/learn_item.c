#define _CRT_SECURE_NO_WARNINGS
#include "learn_item.h"
#include <stdio.h>
void learn_if_else()
{
	float score = 0.0;
	float score1 = 0.0;
	printf("���������ķ���:\n");

	int ret = scanf("%f%f", &score, &score1);
	printf("sancf ret:%d\n", ret);


	if (score > 100)
	{
		printf("��������!\n");
	}
	else if (score >= 90 && score <= 100)
		printf("����!\n");
	else if (score >= 80 && score < 90)
		printf("����!\n");
	else if (score >= 60 && score < 80)
		printf("����!\n");
	else if (score >= 0 && score < 60)
		printf("������!����Ŭ��!\n");
	else
		printf("����ķ�������,�벻Ҫ�Ա�!����Ŭ��!\n");

}