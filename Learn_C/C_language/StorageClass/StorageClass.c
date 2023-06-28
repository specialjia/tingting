#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include<time.h>



int hiding()   // ���еı���
{
	int x = 30;   //ԭʼ��x
	printf("x in outer block: %d at %p\n", x, &x);
	{
		int x = 77;  //�µ�x,����ԭʼ��x
		printf("x in outer block: %d at %p\n", x, &x);
	}
	printf("x in outer block: %d at %p\n", x, &x);
	while (33 >x++)  //ԭʼx 
	{
		int x = 100;  //�µ�x,����ԭʼx
		x++;
		printf("x in while loop: %d at %p\n", x, &x);
	}
	printf("x in outer block: %d at %p\n", x, &x);
}

int forc()   //û�л������ŵĿ�, forѭ��
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
int loc_stat()  //ʹ�þֲ���̬����
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
	int fade = 1;  //ÿ�ε���trystat���������ʼ��fade,stayֻ���ڱ���trystat����ʱ����ʼ��һ��
	static int stay = 1;   //static�洢����˵����,�ṩ��̬�洢��,��̬���ⲿ�����ڳ��������ڴ�ʱ�Ѿ�ִ�����
	printf("fade = %d and stay = %d\n", fade++, stay++);
}

//�ⲿ����: �ؼ��� extern����,  �������Ǵ����������ļ���β,ֻ��ʹ�ó������ʽ��ʼ���ļ����������
int units = 0;    //�ⲿ����ֻ�ܳ�ʼ��һ��
void critic(void);
int global()   // ʹ���ⲿ����
{
	extern int units;  //��ѡ���ظ�����
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
static int count = 0;   //�ļ�������,�ⲿ����
static int total = 0;  //��̬����,�ڲ�����
int parta()   //��ͬ�Ĵ洢���
{
	int value;    //�Զ�����
	register int i;  // �Ĵ�������
	printf("Enter a positive integer (0 to quit):");
	while (1 == scanf("%d", &value) && value > 0)
	{
		++count;  //ʹ���ļ����������
		for (i = value; i >= 0; --i)
			accumulate(i);
		printf("Enter a positive integer (0 to quit):");
	}
}
void accumulate(int k)  // k���п�������,������
{
	static int subtotal = 0;  //��̬������
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
static unsigned long int next = 1; //����
int  r_drive()  //�������������rand0()
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
	next = seed;  //next�����ڲ����ӵ��ļ�������̬����,rand1() srand1()������ʹ����,���������ļ��ĺ����޷�������
}
int r_drive1()   // ����rand1()��srand1()
{
	int count;
	unsigned seed;
	printf("Please enter your choice for seed.\n");
	while (1 == scanf("%u", &seed))
	{
		srand1(seed);  //��������
		for (count = 0; count < 5; ++count)
			printf("%d\n", rand1());
		printf("Please enter next seed (q to quit):\n");
	}
	printf("Done.\n");
}


int roll_count = 0;  //�ⲿ����
static int rollem(int sides)  // �ú��������ļ�˽��
{
	int roll;
	roll = rand() % sides + 1;
	++roll_count;   //���㺯�����ô���
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
int manydice()  // �����ɸ�ӵ�ģ�����
{
	int dice, roll;
	int sides;
	int status;
	srand((unsigned int)time(0)); //�������
	printf("Enetr the number of sides per die,(0 to stop).\n");
	while (1 == scanf("%d", &sides) && sides > 0)
	{
		printf("How many dice?\n");
		if (status = scanf("%d", &dice) != 1)
		{
			if (status == EOF)
				break;   //�˳�ѭ��

			else
			{
				printf("You should have entered an integer.");
				printf("Let's begin again.\n");
				while (getchar() != '\n')
					continue;  //������������
				printf("How many sides? Enter 0 to stop.\n");
				continue;  //����ѭ������һ�ֵ���
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
		printf("How many sides? Enter 0 to stop.\n");
	}
	printf("The rollem() function was called %d times.\n", roll_count);
	printf("GOOD FORTUNE TO YOU!\n");
}

int dyn_arr()   //��̬��������  free������ʹ��
{
	double* ptd;
	int max;
	int number;
	int i = 0;
	puts("What is the maximum number of type double entries?");
	if (1 != scanf("%d", &max))
	{
		puts("Number not correctly entered -- bye");
		exit(EXIT_FAILURE);  //�����ڴ�ʧ��,��������
	}
	ptd = (double*)malloc(max * sizeof(double));  // callloc����Ҳ���Է����ڴ�, ��malloc�÷�����
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
int where()  //���ݱ��洢����  ����Ѿ�̬,�Զ��Ͷ�̬�������洢�ڲ�ͬ������
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

