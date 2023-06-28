#define _CRT_SECURE_NO_WARNINGS
#include "switch.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int animals()  //switch程序读入一个字母,并打印出以该字母开头的动物名称
{
	char ch;
	printf("Give me a letter of the alphabet,and I will give ");
	printf(" an animal name\nbegining with that letter.\n");
	printf("Pelase type in a letter; type # to end my act.\n");
	while ((ch = getchar()) != '#')
	{
		if ('\n' == ch)
			continue;
		if (islower(ch))  // 只接受小写字母
			switch (ch)
			{
			case'a':
				printf("argali, a wild sheep of Asia\n");  //盘羊
				break;
			case'b':
				printf("babirusa, a wild pig of Malay\n");
				break;
			case'c':
				printf("coati, racoonlike mammal\n");
				break;
			case'd':
				printf("desma,aquatic,molelike critter\n");
				break;
			case'e':
				printf("echidna,the spiny anteater\n");
				break;
			default:
				printf(" That's a stumper!\n");   // switch 结束

			}
		else
			printf("I recognize only lowercase letters.\n");
		while (getchar() != '\n')
		{
			continue;  // 跳过输入行的部分
		}
			printf("Please type another leeter or a #.\n");  // 循环结束
	}
	printf("Bye!\n");

}

int vowels()  // 在switch程序中使用多重标签
{
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;
	a_ct = e_ct = i_ct = o_ct = u_ct = 0;
	printf("Enter some text; enter # to quit.\n");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case'a':
		case'A': a_ct++;
			break;
		case'e':
		case'E': e_ct++;
			break;
		case'i':
		case'I':i_ct++;
			break;
		case'o':
		case'O': o_ct++;
			break;
		case'u':
		case'U':o_ct++;
			break;
		defalut: break;

		}  // switch结束
	}   // while循环结束
	printf("number of vowels: A    E    I    O    U\n");  // 元音
	printf("               %4d %4d %4d %4d %4d\n", a_ct, e_ct, i_ct, o_ct, u_ct);


}

int vowels1()
{
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;
	a_ct = e_ct = i_ct = o_ct = u_ct = 0;
	printf("Enter some text; enter # to quit.\n");
	while ((ch = getchar()) != '#')
	{
		ch = toupper(ch);  //将字母转换成大写
		switch (ch)
		{
		case'A': a_ct++;
			break;
		case'E': e_ct++;
			break;
		case'I':i_ct++;
			break;
		case'O': o_ct++;
			break;
		case'U':o_ct++;
			break;
		defalut: break;

		}  // switch结束
	}  // while循环结束
	printf("number of vowels: A    E    I    O    U\n");  // 元音
	printf("               %4d %4d %4d %4d %4d\n", a_ct, e_ct, i_ct, o_ct, u_ct);

}