#define _CRT_SECURE_NO_WARNINGS
#include "ConstantPreprocessor.h"
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159  //�������� һ����  ����ĳ�������PI�����滻�ɳ��� 3.14159

int ConstantPreprocessor()
{
	float area, circum = 0, radius;
	printf("What is the radius of your pizza?\n");
	scanf("%f", &radius);
	area = PI * radius * radius;
	circum = PI * 2 * radius;
	printf(" Your basic pizza parameters are as follows:\n");
	printf("circumference = %1.2f, area = %1.2f\n", circum, area);  //Բ���ܳ�������ļ�����



}