#define _CRT_SECURE_NO_WARNINGS
#include "review.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // 为strlen()提供原型
#define NAME "GIGATHINK, INC"
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

void starbar(void)  //定义函数  创建一个再一行打印40个星号的函数,并在一个打印表头的程序中使用该函数. 没有返回值 没有参数
{
	int count;
	for (count = 1; count <= WIDTH; ++count)
		putchar('*');
	putchar('\n');
}

int letheadl()
{
	starbar();
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);
	starbar(); 
}


void show_n_char(char ch, int num);  // 函数声明
int lethead1()
{
	int spaces;
	show_n_char('*', WIDTH);   //用符号常量作为canshu
	putchar('\n');
	show_n_char(SPACE, 12);   //用符号常量作为canshu
	printf("%s\n", NAME);
	spaces = (WIDTH - strlen(ADDRESS)) / 2;   //计算跳过多少空格

	show_n_char(SPACE, spaces);   //用一个变量作为参数
	printf("%s\n", ADDRESS);
	show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
	printf(" %s\n", PLACE);  // 用一个表达式作为参数
	show_n_char('*', WIDTH);
	putchar('\n');
}

void show_n_char(char ch, int num)
{
	int count;
	for (count = 1; count <= num; ++count)
	{
		putchar(ch);
	}
}
 /*
	void dibs (intx,y,z)  无效函数
	void dibs (int x, int y, int z) 有效函数
	函数类型是指返回值的类型,不是函数参数的类型
*/


// 使用return从函数中返回值
int imin(int n, int m); //函数声明

int lesser() // 找出两个整数中较小的一个
{
	int evi11, evi12;
	printf("Enter a pair of integers (q to quit):\n");
	while (2 == scanf("%d %d", &evi11, &evi12))
	{
		printf("The lesser of %d and %d is %d.\n", evi11, evi12, imin(evi11, evi12));
		printf("Enter a pair of integers (q to quit): \n");
	}
	printf("Bey!\n");
}

int imin(int n, int m)
{
	int min;
	/*
	if (n < m)
		min = n;
	else
		min = m;
	return min;
	*/
	return (n < m) ? n : m;
}


int imax(n, m);  // 函数声明
int misuse()  // 错误的使用函数
{
	printf("The maxium of %d is %d.\n", 3, 5, imax(3,5));   //缺少一个参数
	printf("The maxium of %d is %d.\n", 3, 5, imax(3.0, 5.0));  // 参数类型不匹配
}

int imax(int n, int m)
{
	int a = 0;
	int b = 0;
	return(a > b ? a : b);
}




void up_and_down(int n);
int recur(void)  //递归演示   
{
	up_and_down(1);

}
void up_and_down(int n)
{
	printf("Level %d: n location %p\n", n, &n); // #1 第一级递归
	if (n < 4)
	{
		up_and_down(n + 1);
	}
	printf("Level %d: n location %p\n", n, &n);  //#2
}


long fact(int n);  
long rfact(int n);
int factor()  //使用循环和递归计算阶乘  3的阶乘(1*2*3=3!) 0!等于1  
{
	int num;
	printf("This program calculates factorials.\n");
	printf("Enter a value int the range 0-12(q to quit): \n");
	while (1 == scanf("%d", &num))
	{
		if (num < 0)
		{
			printf("No negative number ,please.\n");  // 不可以是负数
		}
		else if (num > 12)
		{
			printf("Keep input under 13.\n");
		}
		else
		{
			printf("loop: %d factorial = %ld\n", num, fact(num));
			printf("recursion: %d factorial = %ld\n", num, rfact(num));
		}
		printf("Enter a value in the range 0-12 (q to quit):\n");
	}
	printf("Bye.\n");
}

long fact(int n)  // 使用循环的函数
{
	long ans;
	for (ans = 1; n > 1; --n)
	{
		ans *= n;  //等价于 ans = ans * n
	}
	return ans;
}

long rfact(int n)  // 使用递归的函数
{
	long ans;
	if (n > 0)
	{
		ans = n * rfact(n - 1);
	}
	else
		ans = 1;
	return ans;
}


/* 递归和倒叙 */
void to_binary(unsigned long n);
int binary()  //以二进制形式打印整数
{
	unsigned long number;
	printf("Enter an integer (q to quit): \n");
	while (1 == scanf("%lu", &number))
	{
		printf("Binary equivalent: ");
		to_binary(number);
		putchar('\n');
		printf("Enter an integer (q to quit):\n ");

	}
	printf("Done.\n");
}

void to_binary(unsigned long n)
{
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar(0 == r ? '0' : '1');
	return;
}


void mikado(int bah);
int loccheck()  //查看变量被存储在何处
{
	int pooh = 2, bah = 5;
	printf("In main(),pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In main(), bah = %d and &bah = %p\n", bah, &bah);
	mikado(pooh);
}

void mikado(int bah)
{
	int pooh = 10;
	printf("In main(),pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In main(), bah = %d and &bah = %p\n", bah, &bah);

	/*函数调用mikado(pooh)把实际参数main()中的pooh的值(2)传递给形式参数mikado中的bah    */
}


/* 更改主调函数中的变量 */
void change1(int* u, int* v)
{
	int temp;
	temp = *u;  //temp获得u所指向对象的值
	*u = *v;
	*v = temp;
}

int swap()
{
	int x = 5;
	int y = 10;
	printf("Originally x = %d and y = %d.\n", x, y);
	change1(&x, &y); //把地址发送给函数
	printf("Now x = %d and y = %d.\n", x, y);
}


void recursive3()
{
	printf("3\n");
	printf("3\n");
}

void recursive2()
{
	printf("2\n");
	recursive3();
	printf("2\n");
}

void recursive()
{
	printf("1\n");
	recursive2();
	printf("1\n");
}


void recursive_r2(int n)
{
	//printf("%d\n", n);
	
	printf("%d\n", n);
}

void recursive_r(int n)
{
	//printf("%d\n", n);
	if (n < 2999)
	{
		recursive_r(n + 1);
		//recursive2();
	}
	printf("%d\n", n);
}