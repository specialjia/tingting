#define _CRT_SECURE_NO_WARNINGS
#include "digit group.h"
#include <stdio.h>
#include <stdlib.h>
#define YEARS 5
#define MONTHS 12 
#define SIZE 10  //4

int day_mon()  //打印每个月的天数
{
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int index;
	for (index = 0; index < MONTHS; ++index)
	{
		printf("Month %2d has %2d days.\n", index + 1, days[index]);
	}
}

int designate()  // 使用指定初始化器
{
	int days[MONTHS] = { 31,28,[4] = 31,30,31,[1] = 29 };  //再次初始化将会取代之前的初始化,即days[1]初始化28,又被后面的指定初始化[1]=29初始化为29
	int index;
	for (index = 0; index < MONTHS; ++index)
	{
		printf("Month %2d has %2d days.\n", index + 1, days[index]);
	}
}

//数组元素赋值
int ax(void)
{
	int a[5] = { 5,3,2,8 };  //初始化没有问题
	int b[5];
	//b = a;  error
	//b[5] = a[5];   //数组下标越界 正确写法: for(i = 0; i<5; ++i)
	//                                     b[i] = a[i];
	//b[5] = { 5,3,2,8 };  只有在定义数组的同时才可以整体赋值,其他情况下整体赋值都是错误的
}

int bounds()  //数组下标越界
{
	int value1 = 44;
	int arr[SIZE];
	int value2 = 88;
	int i;
	printf("value1 = %d, value2 = %d\n", value1, value2);
	for (i = -1; i <= SIZE; ++i)
	{
		arr[i] = 2 * i + 1;
	}
	for (i = -1; i < 7; ++i)
	{
		printf("%2d %d\n", i ,arr[i]);
	}
	printf("value1 = %d, value2 = %d\n", value1, value2);
	printf("address of arr[-1]: %p\n", &arr[-1]);
	printf("address of arr[4]: %p\n", &arr[4]);
	printf("address of value1: %p\n", &value1);
	printf("address of value2: %p\n", &value2);
}

int rain()
{
	const float rain[YEARS][MONTHS] =
	{
		{3.5,5.9,5.5,4.9},
		{4.5,5.0,6.0,4.8},
		{3.5,5.7,45.6,78.6},

	};
}


int pnt_add()  // 指针和数组,指针地址
{
	short dates[SIZE];
	short* pti;  //占两个字节
	short index;
	double bills[SIZE];  // 占用八个字节
	double* ptf;
	pti = dates;  // 把数值地址赋给指针,  
	// dates == &dates[0] 两者都表示数组首元素的内存地址,数组名是该数组首元素的地址
	ptf = bills;
	printf("%23s %15s\n", "short", "double");
	for (index = 0; index < SIZE; ++index)
	{
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
	}
}
/*
  dates + 2 == &dates[2]  //相同的地址 
  *(dates + 2) == dates[2]  //相同的值
  *(dates + 2)  //dates第三个元素的值
  * dates + 2   // dates第一个元素的值加上2
  
*/

int day_mon1()
{
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int index;
	for (index = 0; index < MONTHS; ++index)
	{
		printf("Month %2d has %d days.\n", index + 1, *(days + index));  //与days[index]相同
	}
}   // days是数组首元素的地址,days+index 是元素days[index]的地址,而 *(days+ index)是该元素的值


int sum(int ar[], int n);
int sum_arr1(void)   // 数组元素之和
{
	int marbles[SIZE] = { 20,10,5,39,4,16,19,26,31,20 };
	long answer=10;
	answer = sum(marbles, SIZE);
	printf("The total number of marbles is %ld.\n", answer);
	printf("The size of marbles is %zd bytes.\n", sizeof(marbles));
}

int sum(int ar[10], int n)   
{
	int i;
	int total = 0;
	for (i = 0; i < n; ++i)
	{
		total += ar[i];
	}
		printf("The size of ar is %zd bytes.\n", sizeof(ar));  // ar是一个指向数组首元素的指针,系统用4字节存储地址
	
}
 
int order()  //指针运算中的优先级
{
	int data[2] = { 100,200 };
	int moredata[2] = { 300,400 };
	int* p1, * p2, * p3;
	p1 = p2 = data;
	p3 = moredata;
	printf("  *p1 = %d,*p2 = %d,*p3 = %d\n", *p1, *p2, *p3);
	printf("*p1++ = %d,*p2++ = %d,(*p3)++ = %d\n", *p1++, *p2++, *p3++);
	printf("  *p1 = %d,*p2 = %d,*p3 = %d\n", *p1, *p2, *p3);
}

int ptr_ops()  // 指针操作
{
	int urn[5] = { 1,2,3,4,5 };
	int* ptr1, * ptr2, * ptr3;
	ptr1 = urn;      // 把一个地址赋给指针
	ptr2 = &urn[2];   // 把一个地址赋给指针
						// 解引用指针,以及获得指针的地址
	printf("pointer value, dereferenced pointer, pointer address:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

	ptr3 = ptr1 + 4;  //指针加法
	printf("\nadding an int to a pointer:\n");
	printf("ptr1 + 4 = %p,*(ptr1+4) = %d\n", ptr1 + 4, *(ptr1 + 4));

	ptr1++;   //递增指针
	printf("\nvalues after ptr1++ :\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

	ptr2--;  //递减指针
	printf("\nvalues after --ptr2 :\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);

	--ptr1;
	++ptr2;  //恢复初始值
	printf("\nPointers reset to original values:\n");
	printf("ptr1 = %p. ptr2 = %p\n", ptr1, ptr2);
	 
	printf("\nsubtracting one pointer from another:\n");  // 一个指针减去另一个指针
	printf("ptr2 = %p.ptr1 = %p,ptr2-ptr2 = %td\n", ptr2, ptr1, ptr2 - ptr1);

	printf("\nsubtracting an int from a pointer :\n");  // 一个指针减去一个整数
	printf("ptr3 = %p.ptr3-2 = %p\n", ptr3, ptr3 - 2);

}