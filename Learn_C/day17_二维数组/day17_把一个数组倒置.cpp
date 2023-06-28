// day17_二维数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
	int a[8] = { 1,2,3,4,5,6,7,8};
	int i, j;
	int t;

	i = 0;
	j = 7;
	while (i < j)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;

		i++;
		--j;
	}
	for (i = 0; i < 8; ++i)
		printf("%d\n", a[i]);

	return 0;
}
