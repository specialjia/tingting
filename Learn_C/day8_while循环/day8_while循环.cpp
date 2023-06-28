// day8_while循环.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//求1+2+3+...+100的和

#include <iostream>

int main()
{
	int i = 0;
	int sum = 0;
	/*/for (i = 0; i <= 100; ++i)
	{
		sum += i;
	}
    */
	i = 1;
	while (i <= 100)
	{
		sum += i;
		++i;
	}

	printf("sum = %d\n", sum);

	return 0;
}

// for(1; 2; 3)
//  A;等价于
// 
//   1
//   while(2)
//    { A; 3}
// whlie和for可以相互转换,但是for的逻辑性更强,推荐多使用for循环