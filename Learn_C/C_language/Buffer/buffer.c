#define _CRT_SECURE_NO_WARNINGS
#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>

int guess()  // һ������Ҵ���ĳ���
{
	int guess = 1;
	char response;
	printf("Pick an integer from 1 to 100. I will try to guess it\n");
	printf("Respond with a y if my guess is right and with\n");
	printf("an n if it is wrong.\n");
	printf("Uh...is your number %d?\n", guess);
	while ((response=getchar()) != 'y')  // ��ȡ��Ӧ,��y���Ա�
	{
		if (response == 'n')
			printf("Well, then, is it %d?\n", ++guess);
		else
			printf("Sorry, I understand only y or n.\n");

		while (getchar() != '\n')
		{
			continue;   //����ʣ���������
			
		}

		
	}
	printf("I knew I could do it!\n");
}