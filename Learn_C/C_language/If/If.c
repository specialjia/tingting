#define _CRT_SECURE_NO_WARNINGS
#include "If.h"
#include <stdio.h>
#include <stdlib.h>

int colddays()  //�ҳ�0 ��C���µ�����ռ�������İٷֱ�
{
	const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;
	printf(" Enter the list of daily low temperature.\n");
	printf("Use celsius,and enter q to quit.\n");  //���϶�
	while (1 == scanf("%f", &temperature))
	{
		++all_days;
		if(temperature < FREEZING)
		++cold_days;
	}
	if (all_days != 0)
		printf("%d days total: %.lf%% were below freezing.\n", all_days, 100.0 * (float)cold_days / all_days);
	if (all_days == 0)
		printf("No data entered!\n");

}