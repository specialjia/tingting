#include "increase.h"
#include <stdio.h>


int  avg(void)
{
	int i = 0;
	int sum = 0;
	int cnt = 0;
	float avg = 0;  //average����д
	for (i = 1; i <= 100; ++i)
	{
		if (i % 2 == 1)
		{
			sum += i;
			++cnt;
		}

	}

	avg = 1.0 * sum / cnt;      //1.0Ĭ����double����
	printf("sum = %d\n", sum);
	printf("cnt = %d\n", cnt);
	printf("cnt = %f\n", avg);

	return 0;

}

int main2(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;

	i = j = 3;   //�ȼ���i=3, j=3;
	k = i++;    //������i++ ������ʽ��ֵ��i��1֮ǰ��ֵ
	m = ++j;    //ǰ����++j ������ʽ��ֵ��j��1֮���ֵ
	printf("i = %d, j = %d,  k = %d, m = %d\n", i, j, k, m);

	return 0;



}