// day46_动态一维数组的构造.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<malloc.h>

int main()
{
	int a[5];   // 如果int占4个字节的话,则本数组总共包含20个字节,每四个字节被当作了一个int变量来使用
	int len;
	int* pArr;
	int i;

	//动态一维数组的构造
	printf("请输入您要存放的元素的个数: ");
	scanf("%d", &len);
	pArr = (int*)malloc(4 * len); // 该一位维数组的长度是len, 数组名是pArr, 该数组的每个元素是int型

	//对一维数组进行操作,  例如对其进行赋值
	for (i = 0; i < len; ++i)
		scanf("%d", &pArr[i]);

	//对一维数组进行输出
	printf("该一位数组的内容是: \n");
	for (i = 0; i < len; ++i)
		printf("%d\n", pArr[i]);

	free(pArr); // 释放掉动态分配的数组

	return 0;
}

  /*14行类似于 int aPrr[len];
  * 静态内存由系统自动分配, 由系统自动释放
* 静态内存是在栈中分配的
*
* 动态内存是由程序员手动分配, 手动释放
* 动态内存是在堆分配的   可以跨函数使用它
*/