#define _CRT_SECURE_NO_WARNINGS
#include "digit group.h"
#include <stdio.h>
#include <stdlib.h>
#define YEARS 5
#define MONTHS 12 
#define SIZE 10  //4

int day_mon()  //��ӡÿ���µ�����
{
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int index;
	for (index = 0; index < MONTHS; ++index)
	{
		printf("Month %2d has %2d days.\n", index + 1, days[index]);
	}
}

int designate()  // ʹ��ָ����ʼ����
{
	int days[MONTHS] = { 31,28,[4] = 31,30,31,[1] = 29 };  //�ٴγ�ʼ������ȡ��֮ǰ�ĳ�ʼ��,��days[1]��ʼ��28,�ֱ������ָ����ʼ��[1]=29��ʼ��Ϊ29
	int index;
	for (index = 0; index < MONTHS; ++index)
	{
		printf("Month %2d has %2d days.\n", index + 1, days[index]);
	}
}

//����Ԫ�ظ�ֵ
int ax(void)
{
	int a[5] = { 5,3,2,8 };  //��ʼ��û������
	int b[5];
	//b = a;  error
	//b[5] = a[5];   //�����±�Խ�� ��ȷд��: for(i = 0; i<5; ++i)
	//                                     b[i] = a[i];
	//b[5] = { 5,3,2,8 };  ֻ���ڶ��������ͬʱ�ſ������帳ֵ,������������帳ֵ���Ǵ����
}

int bounds()  //�����±�Խ��
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


int pnt_add()  // ָ�������,ָ���ַ
{
	short dates[SIZE];
	short* pti;  //ռ�����ֽ�
	short index;
	double bills[SIZE];  // ռ�ð˸��ֽ�
	double* ptf;
	pti = dates;  // ����ֵ��ַ����ָ��,  
	// dates == &dates[0] ���߶���ʾ������Ԫ�ص��ڴ��ַ,�������Ǹ�������Ԫ�صĵ�ַ
	ptf = bills;
	printf("%23s %15s\n", "short", "double");
	for (index = 0; index < SIZE; ++index)
	{
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
	}
}
/*
  dates + 2 == &dates[2]  //��ͬ�ĵ�ַ 
  *(dates + 2) == dates[2]  //��ͬ��ֵ
  *(dates + 2)  //dates������Ԫ�ص�ֵ
  * dates + 2   // dates��һ��Ԫ�ص�ֵ����2
  
*/

int day_mon1()
{
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int index;
	for (index = 0; index < MONTHS; ++index)
	{
		printf("Month %2d has %d days.\n", index + 1, *(days + index));  //��days[index]��ͬ
	}
}   // days��������Ԫ�صĵ�ַ,days+index ��Ԫ��days[index]�ĵ�ַ,�� *(days+ index)�Ǹ�Ԫ�ص�ֵ


int sum(int ar[], int n);
int sum_arr1(void)   // ����Ԫ��֮��
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
		printf("The size of ar is %zd bytes.\n", sizeof(ar));  // ar��һ��ָ��������Ԫ�ص�ָ��,ϵͳ��4�ֽڴ洢��ַ
	
}
 
int order()  //ָ�������е����ȼ�
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

int ptr_ops()  // ָ�����
{
	int urn[5] = { 1,2,3,4,5 };
	int* ptr1, * ptr2, * ptr3;
	ptr1 = urn;      // ��һ����ַ����ָ��
	ptr2 = &urn[2];   // ��һ����ַ����ָ��
						// ������ָ��,�Լ����ָ��ĵ�ַ
	printf("pointer value, dereferenced pointer, pointer address:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

	ptr3 = ptr1 + 4;  //ָ��ӷ�
	printf("\nadding an int to a pointer:\n");
	printf("ptr1 + 4 = %p,*(ptr1+4) = %d\n", ptr1 + 4, *(ptr1 + 4));

	ptr1++;   //����ָ��
	printf("\nvalues after ptr1++ :\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

	ptr2--;  //�ݼ�ָ��
	printf("\nvalues after --ptr2 :\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);

	--ptr1;
	++ptr2;  //�ָ���ʼֵ
	printf("\nPointers reset to original values:\n");
	printf("ptr1 = %p. ptr2 = %p\n", ptr1, ptr2);
	 
	printf("\nsubtracting one pointer from another:\n");  // һ��ָ���ȥ��һ��ָ��
	printf("ptr2 = %p.ptr1 = %p,ptr2-ptr2 = %td\n", ptr2, ptr1, ptr2 - ptr1);

	printf("\nsubtracting an int from a pointer :\n");  // һ��ָ���ȥһ������
	printf("ptr3 = %p.ptr3-2 = %p\n", ptr3, ptr3 - 2);

}