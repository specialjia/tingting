#define _CRT_SECURE_NO_WARNINGS
#include "bit.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/*
	һԪ����� �����Ʒ����λȡ��:~  �����val��ֵ��Ϊ~val,ʹ�����: val  = ~val;
	��Ԫ����� ��λ��:& ��λ�Ƚ�����������������µ�ֵ,���������������Ӧ��λ��λ1ʱ,�������1
	��Ԫ��λ��:| ��λ�Ƚ�����������������µ�ֵ,���������������ӦλΪ1,�������1(����һ��λΪ1��������Ϊ1)
	��Ԫ��λ���:^ ��λ�Ƚ������������,���������������Ӧλһ��Ϊ1,���Ϊ1(һ��Ϊ1��������ͬΪ1)
				(10010011)^(00111101) �����(10101110)
*/
char* itobs(int, char*);
void show_bstr(const char*);  //itbos��������ת���ɶ������ַ���
int binbit()  //ʹ��λ������ʾ������
{
	char bin_str[CHAR_BIT * sizeof(int) + 1];  //����һ���ַ�����,��int���͵Ķ����Ʊ�ʾ��λ������һ���ַ����ڽ�β��־
	int number;
	puts("Enter integers and see them in binary."); //binary ������ ��Ԫ
	puts("Non-numeric input terminates program.");
	while (scanf("%d", &number) == 1)
	{
		itobs(number, bin_str);
		printf("%d is ", number);
		show_bstr(bin_str);
		putchar('\n');
	}
	puts("bye!");
}
char* itobs(int n, char* ps)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';
	return ps;
}
void show_bstr(const char* str)  //4λһ����ʾ�������ַ���
{
	int i = 0;
	while (str[i]) // ����һ�����ַ�
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}
}


int invert_end(int num, int bits);
int invert()    //�л�һ��ֵ�еĺ�nλ 
{
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	int number;
	puts("Enter integers and see them in binary.");
	puts("Non-numeric input terminates program.");
	while (scanf("%d", &number) == 1)
	{
		itobs(number, bin_str);
		printf("%d is\n", number);
		show_bstr(bin_str);
		putchar('\n');
		number = invert_end(number, 4);
		printf("Inverting the last 4 bits gives\n");
		show_bstr(itobs(number, bin_str));
		putchar('\n');
	}
	puts("bey!");
}
int invert_end(int num, int bits)
{
	int mask = 0;
	int bitval = 1;
	while (bits-- > 0)
	{
		mask |= bitval;
		bitval <<= 1;
	}
	return num ^ mask;
}