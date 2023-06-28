// day20_函数举例.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/*int f(void)  // 括号中的void表示该函数不能接收数据   int表示函数返回值是int类型
{
	return 10; // 向主调函数(main函数)返回10
}

void g(void)  // 函数名称前面的void表示该函数没有返回值
{
	// return 0;  // error 与11行行首的void相矛盾
}

int main()
{
	int j = 88;
	j = f();
	printf("%d\n", j);
	//j = g();// error 因为g函数没有返回值


	return 0;
}
*/

float f(int i)
{
	return 10.00;
}
int main()
{
	float i = 99.9;
		printf("%lf\n", i);
         i = f(5);
		printf("%lf\n", i);



	return 0;
}

//