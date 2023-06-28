#define _CRT_SECURE_NO_WARNINGS
#include "bit.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/*
	一元运算符 二进制反码或按位取反:~  如如果val的值改为~val,使用语句: val  = ~val;
	二元运算符 按位与:& 逐位比较两个运算对象生成新的值,两个运算对象中相应的位都位1时,结果才是1
	二元按位或:| 逐位比较两个运算对象生成新的值,两个运算对象中相应位为1,结果就是1(其中一个位为1或两个都为1)
	二元按位异或:^ 逐位比较两个运算对象,两个运算对象中相应位一个为1,结果为1(一个为1不是两个同为1)
				(10010011)^(00111101) 结果是(10101110)
*/
char* itobs(int, char*);
void show_bstr(const char*);  //itbos函数整数转换成二进制字符串
int binbit()  //使用位操作显示二进制
{
	char bin_str[CHAR_BIT * sizeof(int) + 1];  //定义一个字符数组,即int类型的二进制表示的位数加上一个字符用于结尾标志
	int number;
	puts("Enter integers and see them in binary."); //binary 二进制 二元
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
void show_bstr(const char* str)  //4位一组显示二进制字符串
{
	int i = 0;
	while (str[i]) // 不是一个空字符
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}
}


int invert_end(int num, int bits);
int invert()    //切换一个值中的后n位 
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