#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include<time.h>



int hiding()   // 块中的变量
{
	int x = 30;   //原始的x
	printf("x in outer block: %d at %p\n", x, &x);
	{
		int x = 77;  //新的x,隐藏原始的x
		printf("x in outer block: %d at %p\n", x, &x);
	}
	printf("x in outer block: %d at %p\n", x, &x);
	while (33 >x++)  //原始x 
	{
		int x = 100;  //新的x,隐藏原始x
		x++;
		printf("x in while loop: %d at %p\n", x, &x);
	}
	printf("x in outer block: %d at %p\n", x, &x);
}

int forc()   //没有花花括号的块, for循环
{
	int n = 8;
	printf("   Initially, n = %d at %p\n", n, &n);
	for (int n = 1; n < 3; ++n)
		printf("loop1:n = %d at %p\n", n, &n);
	printf("After loop1,n = %d at %p\n", n, &n);
	for (int n = 1; n < 3; ++n)
	{
		printf("loop2 index n = %d at %p\n", n, &n);
		int n = 6;
		printf("loop2: n= %d at %p\n", n, &n);
		++n;
	}
	printf("After loop2, n= %d at %p\n", n, &n);

}

void trystat(void);
int loc_stat()  //使用局部静态变量
{
	int count;
	for (count = 1; count <= 3; ++count)
	{
		printf("Here comes iteration %d:\n", count);
		trystat();
	}
}
void trystat(void)
{
	int fade = 1;  //每次调用trystat函数都会初始化fade,stay只是在编译trystat函数时被初始化一次
	static int stay = 1;   //static存储类型说明符,提供静态存储期,静态和外部变量在程序被载入内存时已经执行完毕
	printf("fade = %d and stay = %d\n", fade++, stay++);
}

//外部连接: 关键字 extern声明,  作用域是从声明处到文件结尾,只能使用常量表达式初始化文件作用域变量
int units = 0;    //外部变量只能初始化一次
void critic(void);
int global()   // 使用外部变量
{
	extern int units;  //可选的重复声明
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while (units != 56)
		critic();
	printf("You must have looked it up!\n");
}
void critic(void)
{
	printf("No luck,my friend. try again.\n");
	scanf("%d", &units);
}


void accumulate(int k);
static int count = 0;   //文件作用域,外部链接
static int total = 0;  //静态定义,内部链接
int parta()   //不同的存储类别
{
	int value;    //自动变量
	register int i;  // 寄存器变量
	printf("Enter a positive integer (0 to quit):");
	while (1 == scanf("%d", &value) && value > 0)
	{
		++count;  //使用文件作用域变量
		for (i = value; i >= 0; --i)
			accumulate(i);
		printf("Enter a positive integer (0 to quit):");
	}
}
void accumulate(int k)  // k具有块作用域,无链接
{
	static int subtotal = 0;  //静态无链接
	if (k <= 0)
	{
		printf("loop cycle:%d \n", count);
		printf("subtotal: %d;total:%d\n", subtotal, total);
	}
	else
	{
		subtotal += k;
		total += k;
	}
}


extern unsigned int rand0(void);
static unsigned long int next = 1; //种子
int  r_drive()  //测试随机数函数rand0()
{
	int count;
	for (count = 0; count < 5; ++count)
		printf("%d\n", rand0());
}
unsigned int rand0(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

extern void srand1(unsigned int x);
extern int rand1(void);
int rand1(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}
void srand1(unsigned int seed)
{
	next = seed;  //next具有内部链接的文件作用域静态变量,rand1() srand1()都可以使用它,但是其他文件的函数无法访问它
}
int r_drive1()   // 测试rand1()与srand1()
{
	int count;
	unsigned seed;
	printf("Please enter your choice for seed.\n");
	while (1 == scanf("%u", &seed))
	{
		srand1(seed);  //重置种子
		for (count = 0; count < 5; ++count)
			printf("%d\n", rand1());
		printf("Please enter next seed (q to quit):\n");
	}
	printf("Done.\n");
}


int roll_count = 0;  //外部链接
static int rollem(int sides)  // 该函数属于文件私有
{
	int roll;
	roll = rand() % sides + 1;
	++roll_count;   //计算函数调用次数
	return roll;
}
int roll_n_dice(int dice, int sides)
{
	int d;
	int total = 0;
	if (sides < 2)
	{
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if (dice < 1)
	{
		printf("Need at least 1 die.\n");
		return -1;
	}
	for (d = 0; d < dice; ++d)
	{
		total += rollem(sides);
	}
	return total;
}
int manydice()  // 多次掷筛子的模拟程序
{
	int dice, roll;
	int sides;
	int status;
	srand((unsigned int)time(0)); //随机种子
	printf("Enetr the number of sides per die,(0 to stop).\n");
	while (1 == scanf("%d", &sides) && sides > 0)
	{
		printf("How many dice?\n");
		if (status = scanf("%d", &dice) != 1)
		{
			if (status == EOF)
				break;   //退出循环

			else
			{
				printf("You should have entered an integer.");
				printf("Let's begin again.\n");
				while (getchar() != '\n')
					continue;  //处理错误的输入
				printf("How many sides? Enter 0 to stop.\n");
				continue;  //进入循环的下一轮迭代
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
		printf("How many sides? Enter 0 to stop.\n");
	}
	printf("The rollem() function was called %d times.\n", roll_count);
	printf("GOOD FORTUNE TO YOU!\n");
}

int dyn_arr()   //动态分配数组  free函数的使用
{
	double* ptd;
	int max;
	int number;
	int i = 0;
	puts("What is the maximum number of type double entries?");
	if (1 != scanf("%d", &max))
	{
		puts("Number not correctly entered -- bye");
		exit(EXIT_FAILURE);  //分配内存失败,结束程序
	}
	ptd = (double*)malloc(max * sizeof(double));  // callloc函数也可以分配内存, 与malloc用法类似
	if (ptd == NULL)
	{
		puts("Memory allocation failed.Goodbye.");
		exit(EXIT_FAILURE);
	}
	puts("Enter the value (q to quit):");
	while(i < max && 1 == scanf("%lf", &ptd[i]))
		++i;
	printf("Here are your %d entries:\n", number = i);
	for (i = 0; i < number; ++i)
	{
		printf("%7.2f", ptd[i]);
		if (i % 7 == 6)
			putchar('\n');
	}
	if (i % 7 != 0)
		putchar('\n');
	puts("Done.");
	free(ptd);
}


int static_store = 30; 
const char* pcg = "String Literal";
int where()  //数据被存储在哪  程序把静态,自动和动态分配对象存储在不同的区域
{
	int auto_store = 40;
	char auto_string[] = "Auto char array";
	int* pi;
	char* pcl;
	pi = (int*)malloc(sizeof(int));
	*pi = 35;
	pcl = (char*)malloc(strlen("Dynamic String") + 1);
	strcpy(pcl, "Dynamic String");
	printf("static_store: %d at %p\n", static_store, &static_store);
	printf("  auto_store: %d at %p\n", auto_store, &auto_store);
	printf("         *pi: %d at %p\n", *pi, pi);
	printf("  %s at %p\n", pcg, &pcg);
	printf(" %s at %p\n", auto_string, &auto_string);
	printf("  %s at %p\n", pcl, &pcl);
	printf("   %s at %p\n", "Quoted String", "Quoted String");
	free(pi);
	free(pcl);
}

