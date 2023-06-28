#define _CRT_SECURE_NO_WARNINGS
#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>

int guess()  // 一个拖沓且错误的程序
{
	int guess = 1;
	char response;
	printf("Pick an integer from 1 to 100. I will try to guess it\n");
	printf("Respond with a y if my guess is right and with\n");
	printf("an n if it is wrong.\n");
	printf("Uh...is your number %d?\n", guess);
	while ((response=getchar()) != 'y')  // 获取响应,与y做对比
	{
		if (response == 'n')
			printf("Well, then, is it %d?\n", ++guess);
		else
			printf("Sorry, I understand only y or n.\n");

		while (getchar() != '\n')
		{
			continue;   //跳过剩余的输入行
			
		}

		
	}
	printf("I knew I could do it!\n");
}