#define _CRT_SECURE_NO_WARNINGS
#include "input.h"
#include <stdio.h>
#include <stdbool.h>  // ��֤������һ������
long get_long(void);  // ��֤��Χ���������Ƿ���Ч
bool bad_limits(long begin, long end, long low, long high);  //����a~b������ƽ����
double sum_squares(long a, long b);

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);



void display(char cr, int lines, int width);
int showchar()  
{ 
	int ch;     //����ӡ�ַ�
	int rows, cols;  //��ӡ������
	printf("Enter a character and two integers:\n");
	while ((ch = getchar()) != '\n')
	{
		if (2 != (scanf("%d %d", &rows, &cols)))   // %d���治Ҫ�пո�
			break; 
		display(ch, rows, cols);
		while (getchar() != '\n')
		{ 
			continue;    //��̫����京��
		}
		printf("Enter another character and two integers:\n");
		printf("Enter a newline to quit.\n");
	}
	printf("Bey!\n");

}

void display(char cr, int lines, int width)
{
	int row, col;
	for (row = 1; row <= lines; ++row)
	{
		for (col = 1; col <= width; ++col)
		{
			putchar(cr);
		}
		putchar('\n');  //����һ�в���ʼ�µ�һ��
		
	}

}
int checking() //������֤
{
	const long MIN = -10000000L;  //��Χ������
	const long MAX = +10000000L;  //��Χ������
	long start;   //�û�ָ���ķ�Χ��Сֵ
	long stop;    //�û�ָ���ķ�Χ���ֵ
	double answer;
	printf("This program computers the sum of the squares of integer in a range.\nThe lower bound should not"
		"be less than -10000000 and\nthe upper bound should not be more than +10000000.\n"
		"Enter the limits (enter 0 for both limits to quit):\nlower limit:");
	start = get_long();
	printf("upper limit: ");
	stop = get_long();
	while (0 != start || 0 != stop)
	{
		if (bad_limits(start, stop, MIN, MAX))
		{
			printf("Please try again.\n");
		}
		else
		{
			answer = sum_squares(start, stop);
			printf("The sum of the squares of the integers ");
			printf("from %ld to %ld is %g\n", start, stop, answer);  //%g������ֵ�Ĵ�С�Զ�ѡ�������ʽ%f��%e
		}
		printf("Enter the limits (enter 0 for both limits to quit): \n");
		printf("lower limit: ");
		start = get_long();
		printf("upper limit: ");
		stop = get_long();
	}
	printf("Done!\n");
}

long get_long(void)
{
	long input;
	char ch;
	while (1 != (scanf("%ld", &input)))
	{
		while ((ch = getchar()) != '\n')  
		{
			putchar(ch);  //�����������
		}
		printf(" is not an integer.\nPlease enter an integer value,such as 25,-178,or 3: ");
	}
	return input;
}

double sum_squares(long a, long b)
{
	double total = 0;
	long i;
	for (i = a; i <= b; ++i)
	{
		total += (double)i * (double)i;
	}
	return total;
}

bool bad_limits(long begin, long end, long low, long high)
{
	bool not_good = false;
	if (begin > end)
	{
		printf("%ld isn't smaller than %ld.\n", begin, end);
		not_good = true;
	}
	if (begin < low || end < low)
	{
		printf("Value must be %ld or greater.\n", low);
		not_good = true;
	}
	if (begin > high || end > high)
	{
		printf("Values must be %ld or less.\n", high);
		not_good = true;
	}
	return not_good;
}




int menuette()  //�˵�����
{
	int choice;
	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
		case 'a': printf("Buy low, sell high.\n");
			break;
		case 'b':putchar('\a');  //����
			break;
		case 'c': count();
			break;
		default: printf("Program error!\n");
			break;

		}
	}
	printf("Bey.\n");

}

void count(void)
{
	int n, i;
	printf("Count how far? Enter an integer: \n");
	n = get_int();
	for (i = 1; i <= n; ++i)
	{
		printf("%d\n", i);
	}
	while (getchar() != '\n')
	{
		continue;
	}
}

char get_choice(void)
{
	int ch;
	printf("Enter the letter of your choice:\n");
	printf("a.  advice     b.  bell\n");
	printf("c.  count      d.  quit\n");
	ch = get_first();
	while (ch < 'a' || ch>'c' && ch != 'q')
	{
		printf("Please respond with a, b ,c, or q.\n");
		ch = get_first();

	}
	return ch;
}

char get_first()
{
	int ch;
	ch = getchar();
	while (getchar() != '\n')
	{
		continue;
	}
	return ch;

}

int get_int(void)
{
	int input;
	char ch;
	while (1 != (scanf("%d", &input)))
	{
		while ((ch = getchar()) != '\n')
		{
			putchar(ch);  //����������
		}
		printf(" is not an integer.\nPlease enter an integer value,such as 25,-178,or 3: ");
		
	}
	return input;
}