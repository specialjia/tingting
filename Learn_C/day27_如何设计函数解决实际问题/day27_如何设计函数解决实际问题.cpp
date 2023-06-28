// day27_如何设计函数解决实际问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  求1到100所有素数,并输出,只用main函数实现又局限性, 代码重用性不高,代码不容易理解
//   用一个函数来判断 ,代码重用性还不是很高



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

bool isprime( int m)
{
	int i;
	for (i = 2; i < m; ++i)
	{
		if (m % i == 0)  // i对j取余数
			break;
	}
	if (i == m)
		return true;
	else
		return false;
}
int main()
{
	int val;
	int i;
	int j;
	scanf("%d", &val);
	for (i = 2; i <= val; ++i)
	{
		if (isprime(i))
			printf("%d\n", i);
	}

	return 0;
}

// 用单独的函数来实现,代码的可重用性提高