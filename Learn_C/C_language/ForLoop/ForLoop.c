#define _CRT_SECURE_NO_WARNINGS
#include "ForLoop.h"
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
 

#define SIZE 10
#define PAR 72

int sweetie() // forѭ������
{
	const int NUMBER = 22;
	int count = 1;
	for (count; count <= NUMBER; ++count)
	{
		printf("Be my Valentine!\n");
	}
}

int for_cube()  // forѭ����һ��������
{
	int num;
	printf("   n    n cube\n");
	for (num = 1; num <= 6; ++num)
	{
		printf("%5d %5d\n", num, num * num * num);

	}
}

int for_down()  // �ݼ���������ݼ�������
{
	int secs;
	for (secs = 5; secs > 0; --secs)
	{
		printf("%d seconds!\n", secs);
	}
	printf(" We have ignition!\n");  //���

}
int for_13s() // ����������13
{
	int n = 2;
	for (n; n < 60; n = n + 13)
	{
		printf("%d\n", n);
	}
}

int for_char() //���ַ��������ּ���
{
	char  ch;
	for (ch = 'A'; ch <= 'Z'; ++ch)
	{
		printf("The ASCII value for %c is %d.\n", ch,ch);
	}
}
int for_geo()  //Ƿ�����������������(10%)
{
	double debt;
	for (debt = 100; debt < 150; debt = debt * 1.1)
	{
		printf("Your debt is now $%.2f.\n", debt);
	}
}

int for_none() // ʡ��һ�����߶�����ʽ,���ǷֺŲ���ʡ��
{
	int ans, n;
	ans = 2;
	for (n = 3; ans <= 25;)//�ֺŲ���ʡ��
	{
		ans = ans * n;
	}
	printf("n= %d; ans = %d", n, ans);
}
int for_show() // ֻ�Ե�1�����ʽ��ֵһ�λ�ִ��һ��
{
	int num = 0;
	for (printf("Keep entering numbers!\n"); num != 6;)
	{
		scanf("%d", &num);
	}
	printf("That's the one I want!\n");

}

int for_zeno()  // zenor����  ������֮��  1+1/2+1/4+1/8+...
{
	int t_ct;  //�����
	double time, power_of_2;
	int limit;
	printf("Enter the number of terms you want: ");
	scanf("%d", &limit);
	for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; ++t_ct, power_of_2 *= 2.0)
	{
		time += 1.0 / power_of_2;
	}
	printf("time =  %f when terms = %d.\n", time, t_ct);

}

int scores() //ѭ����������
{
	int index, score[SIZE]; //size=10
	int sum = 0;
	float average;
	printf("Enter %d golf socres:\n", SIZE);
	for (index = 0; index < SIZE; ++index)
	{
		scanf("%d", &score[index]);  //��ȡʮ������
	}
	printf("The scores raed in are as follows:\n");
	for (index = 0; index < SIZE; ++index)
	{
		printf("%5d", score[index]); //��֤����
	}
	printf("\n");
	for (index = 0; index < SIZE; ++index)
	{
		sum += score[index]; // ���ܺ�
	}
	average = (float)sum / SIZE; // ��ƽ����
	printf("Sum of scores = %d, average = %.2f\n", sum, average);
	printf("That's a handicap of %.0f.\n", average - PAR);

}

double power(double n, int p); // ANSI����ԭ�� ��������
int pow1()  //��������������
{
	 
	double x, xpow;
	int exp;  // ָ����

	printf("Enter a number and the positive integer power to which\n");
	printf("the numbe will be raised. (Enter  q to quit)");
	while (2 == scanf("%lf %d", &x, &exp))
	{
		xpow = power(x, exp); // ��������
		printf("%.3g to the power %d is %5g\n", x, exp, xpow);  // ������ֵ%g�Զ������ʽ
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoyed this power trip-- bye!\n");
	return 0;
}
double power(double n, int p) // ��������
{
	double pow = 1;
	int i;
	for (i = 1; i <= p; ++i)
	{
		pow *= n;

	}
	return pow;  //����pow��ֵ
}


int islower_userdefine(char ch)
{
	char ch1;
	printf("%c\n", ch);

}