// day28_如何设计函数解决实际问题2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 用两个函数来实现求1到100所有素数,并输出,  
// 本程序代码量更少,代码重用性很高


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
bool isprime(int m);

void traverseval(int n) //本函数功能是把1到n之间所有的素数在显示器上输出
{
	int i;
	for (i = 2; i <= n; ++i)
	{
		if (isprime(i))
			printf("%d\n", i);
	}
	 
}

	bool isprime(int m)  // 本函数功能是判断m是否为素数,是返回true, 不是返回false
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
		
		scanf("%d", &val);
		traverseval(val);
	
	return 0;
}

// 一个函数的功能尽量独立,单一
// 多学习,多模仿牛人代码
// 函数是cy语言的基本单位,类是java,c#,c++基本单位