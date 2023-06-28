// day45_malloc函数的用法 续.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
# include <malloc.h>
void f(int * q)
{
	/*
	  * p = 200;    error
	  q = 200;      error
	  * * q = 200;  error
	*/
	*q = 200;
	// free(q); // error 把q所指向的内存释放掉,本语句必须注释掉,否到导致24行代码出错

}

int main()
{
	int* p = (int*)malloc(sizeof(int)); //  sizeof(int) 返回值是int所占的字节数
	* p = 10;
	printf("%d\n", *p); // 10
	f(p);
	printf("%d\n", *p);  //200


	return 0;
}

// 