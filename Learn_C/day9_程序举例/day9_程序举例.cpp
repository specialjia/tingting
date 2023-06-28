// day9_程序举例.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//菲波拉契序列  1 2 3 5 8 13 21 34 
// f(n)= f(n-1) + f(n-2)


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int n =  0;
	int f1, f2, f3;
	int i = 0;
	f1 = 1;
	f2 = 2;
	printf("请输入您需要求的项的序列: ");
	scanf("%d", &n);

	if (1 == n)
	{
		f3 = 1;
	}
	else if (2 == n)
	{
		f3 = 2;
	}
	else
	{
		for (i = 3; i <= n; ++i)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
	}
	printf("%d\n", f3);

	return 0;
}

