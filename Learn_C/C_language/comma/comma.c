#define _CRT_SECURE_NO_WARNINGS
#include "comma.h"
#include <stdio.h>
#include<stdlib.h>

int postage()  // һ������
{
	const int FIRST_OZ = 46;  //2013���� ����
	const int NEXT_OZ = 20;  // 2013���� ����
	int ounces, cost;  // ����Ϊ����/��˾

	printf("ounces   cost\n");
	for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ++ounces, cost += NEXT_OZ)
	{
		printf(" %5d  $%4.2f\n", ounces, cost / 100.0);
	}
}

/*
 x = (y = 3, (z = ++y +2) +5) ,�������ʽ��ֵ�Ƕ����Ҳ��ֵ,��11

 h = 249,550 ���������� h=249; 500;   249f��ֵ��h,500�Ǳ��ʽ��ֵ
 h = (249,500) �� h=500; d�����Ҳ��ֵ
 ����Ҳ�������ָ���
 char ch,date;
 printf("%d %d \n", chimps,chumps)


*/