#define _CRT_SECURE_NO_WARNINGS
#include "TypeConversion.h"
#include <stdio.h>
#include <stdlib.h>

int convert()  //自动类型转换
{
	char ch;
	int i;
	float f1;
	f1 = i = ch = 'C';
	printf("ch = %c, i = %d, f1 = %2.2f\n", ch, i, f1);

	ch = ch + 1;
	i = f1 + 2 * ch;
	f1 = 2.0 * ch + i;
	printf("ch = %c, i = %d, f1 = %2.2f\n", ch, i, f1);

	ch = 1107;
	printf("Now ch = %c\n", ch);
	ch = 80.89;
	printf("Now ch = %c\n",ch);

	ch = 'S';
	printf("%d\n", ch);

	/* 运行结果
	ch = C, i = 67, f1 = 67.00
	ch = D, i = 203, f1 = 339.00                      
	Now ch = S
	Now ch = P
	
	
	*/

}
