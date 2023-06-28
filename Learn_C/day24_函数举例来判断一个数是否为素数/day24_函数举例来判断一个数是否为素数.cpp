// day24_函数举例来判断一个数是否为素数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

 


/*	max1(a, b);
	max1(c, d);
	max1(e, f);
*/
/*
	return 0;
}
*/

bool Isprime(int val)   //
{
	int i = 0;
	for (i = 2; i < val; ++i)
	{
		if (i % val == 0)
		{
			break;
		}
	}
	if (i == val)
		return true;
	else
		return false;
}

int main()  // 判断是否为素数
{
	int m;

	scanf("%d", &m);

	if (Isprime(m))
		printf("Yes\n");
	else
		printf("No\n");


	return 0;
}