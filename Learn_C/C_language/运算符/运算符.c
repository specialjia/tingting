#define _CRT_SECURE_NO_WARNINGS
#include "�����.h"
#include <stdio.h>
#include <stdlib.h>
#define COVERAGE 350  //ÿ�������ˢ�����(��λ:ƽ��Ӣ��)

int paint()  // ʹ�����������:?
{
	int sq_feet;
	int cans;
	printf("Enter number of square to be painted: \n");
	while (1 == scanf("%d", &sq_feet))
	{
		cans = sq_feet / COVERAGE;
		cans += (sq_feet % COVERAGE == 0) ? 0 : 1; // sq�ܷ�����COVERAGE  ���ԵĻ�ֵΪ0 ,������ֵ����1
		printf("You need %d %s of paint.\n", cans, cans = 1 ? "can" : "cans");
		printf("Enter next value(q to quit) :");
	}
}
// ����������