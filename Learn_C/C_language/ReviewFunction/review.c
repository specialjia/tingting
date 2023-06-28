#define _CRT_SECURE_NO_WARNINGS
#include "review.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Ϊstrlen()�ṩԭ��
#define NAME "GIGATHINK, INC"
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

void starbar(void)  //���庯��  ����һ����һ�д�ӡ40���Ǻŵĺ���,����һ����ӡ��ͷ�ĳ�����ʹ�øú���. û�з���ֵ û�в���
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


void show_n_char(char ch, int num);  // ��������
int lethead1()
{
	int spaces;
	show_n_char('*', WIDTH);   //�÷��ų�����Ϊcanshu
	putchar('\n');
	show_n_char(SPACE, 12);   //�÷��ų�����Ϊcanshu
	printf("%s\n", NAME);
	spaces = (WIDTH - strlen(ADDRESS)) / 2;   //�����������ٿո�

	show_n_char(SPACE, spaces);   //��һ��������Ϊ����
	printf("%s\n", ADDRESS);
	show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
	printf(" %s\n", PLACE);  // ��һ�����ʽ��Ϊ����
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
	void dibs (intx,y,z)  ��Ч����
	void dibs (int x, int y, int z) ��Ч����
	����������ָ����ֵ������,���Ǻ�������������
*/


// ʹ��return�Ӻ����з���ֵ
int imin(int n, int m); //��������

int lesser() // �ҳ����������н�С��һ��
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


int imax(n, m);  // ��������
int misuse()  // �����ʹ�ú���
{
	printf("The maxium of %d is %d.\n", 3, 5, imax(3,5));   //ȱ��һ������
	printf("The maxium of %d is %d.\n", 3, 5, imax(3.0, 5.0));  // �������Ͳ�ƥ��
}

int imax(int n, int m)
{
	int a = 0;
	int b = 0;
	return(a > b ? a : b);
}




void up_and_down(int n);
int recur(void)  //�ݹ���ʾ   
{
	up_and_down(1);

}
void up_and_down(int n)
{
	printf("Level %d: n location %p\n", n, &n); // #1 ��һ���ݹ�
	if (n < 4)
	{
		up_and_down(n + 1);
	}
	printf("Level %d: n location %p\n", n, &n);  //#2
}


long fact(int n);  
long rfact(int n);
int factor()  //ʹ��ѭ���͵ݹ����׳�  3�Ľ׳�(1*2*3=3!) 0!����1  
{
	int num;
	printf("This program calculates factorials.\n");
	printf("Enter a value int the range 0-12(q to quit): \n");
	while (1 == scanf("%d", &num))
	{
		if (num < 0)
		{
			printf("No negative number ,please.\n");  // �������Ǹ���
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

long fact(int n)  // ʹ��ѭ���ĺ���
{
	long ans;
	for (ans = 1; n > 1; --n)
	{
		ans *= n;  //�ȼ��� ans = ans * n
	}
	return ans;
}

long rfact(int n)  // ʹ�õݹ�ĺ���
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


/* �ݹ�͵��� */
void to_binary(unsigned long n);
int binary()  //�Զ�������ʽ��ӡ����
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
int loccheck()  //�鿴�������洢�ںδ�
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

	/*��������mikado(pooh)��ʵ�ʲ���main()�е�pooh��ֵ(2)���ݸ���ʽ����mikado�е�bah    */
}


/* �������������еı��� */
void change1(int* u, int* v)
{
	int temp;
	temp = *u;  //temp���u��ָ������ֵ
	*u = *v;
	*v = temp;
}

int swap()
{
	int x = 5;
	int y = 10;
	printf("Originally x = %d and y = %d.\n", x, y);
	change1(&x, &y); //�ѵ�ַ���͸�����
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