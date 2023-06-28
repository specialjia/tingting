// day39_指针使函数返回一个以上的值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  如何通过被调函数修改主调函数普通变量的值

#include <iostream>

 int f(int i, int j)
{
	 return 100;
}

 void g(int* p, int* q)
 {
	 *p = 2;
	 *q = 1;



 }

int main()
{
	int a = 3, b = 5;
	 g(&a,&b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}

//  1.  实参必须为该普通变量的地址
//   2. 形参必须为指针变量
//   3. 在被调函数中通过  * 形参名 = ....   的方式就可以修改主调函数相关变量的值