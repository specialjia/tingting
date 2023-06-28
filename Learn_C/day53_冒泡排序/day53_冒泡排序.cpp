// day53_冒泡排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void sort(int * a, int len)
{
	int i, j, t;
	for (i = 0; i < len; ++i)
	{
		for (j = 0; j < len - 1 - i; ++j)
		{
			if (a[j] > a[j +1])   // >表示升序
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;

			}



		}


	}


}

int main()
{
	int a[6] = { 10,2,8,-8,11,0 };
	int i = 0;
	sort(a, 6);
	for (i = 0; i < 6; ++i)
	{
		printf("%d", a[i]);
	}
	printf("\n");


	return 0;
}

// 