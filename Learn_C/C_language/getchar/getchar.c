#define _CRT_SECURE_NO_WARNINGS
#include "getchar.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>     //为isspace() 函数提供原型
#include <stdbool.h>   // 为bool,true,false提供定义
#define SPACE ' '
#define PERIOD '.'
#define STOP '|'

int cypher()  //更改输入,空格不变
{
	char ch;
	ch = getchar();  //读取一个字符
	while (ch != '\n')  // 当一行未结束时
	{
		if (ch == SPACE) //留下空格
			putchar(ch);  // 该字符不变
		else
			putchar(ch + 1);  // 改变该字符
		ch = getchar(); // 获取下一个字符
	}
	putchar(ch); //打印换行符

}

int cypher1()  //替换输入的字母,非字母字符报纸不变
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))  // 如果时一个字符
			putchar(ch + 1); //显示该字符的下一个字符
		else
			putchar(ch); // 原样显示
	}
	putchar(ch);

}  // 大小写字母均被替换了,除了空格和标点符号



int chcount()  // 使用逻辑与运算符
{
	char ch;
	int charcount = 0;
	while (ch = getchar() != PERIOD)
	{
		if (ch != '"' && ch != '\'')  //不是双引号也不是单引号
			++charcount;
	}
	printf("There are %d non-quote characters.\n", charcount);

	// 3种逻辑运算符 &&:与(and)   ||:或(or)   !:非(not)
}
/*
	优先级: 
	!的优先级很高,比乘法运算高,与递增运算符优先级相同,只比圆括号的优先级低;
	&&比||优先级高,两者都比关系运算符低,比赋值运算符高;
	a > b && b > c || b >d  相当于  (a > b) && (b > c) || (b >d)

*/


int wordcnt()  // 统计字符数,单词数,行数
{
	char c;     // 读入字符
	char prev;  //读入前一个字符
	long n_chars = 0L;  //字符数
	int n_lines = 0;   //行数
	int n_words = 0;   //单词数
	int p_lines = 0;   //不完整的行数
	bool inword = false;  //如果c在单词中, inword等于true

	printf("Plesae enter text to be analyzed ( | to terminate):\n");
	prev = '\n';    //用于识别完整的行
	while ((c = getchar()) != STOP)
	{
		n_chars++;    //统计字符
		if (c == '\n')
			n_lines++;  //统计行数
		if (!isspace(c) && !inword)
		{
			inword = true;  // 开始一个新的单词
			n_words++;      // 统计单词
		}
		if (isspace(c) && inword)
			inword = false;  //到达单词的末尾
		prev = c;            //保存字符的值
	}
	if (prev != '\n')
		p_lines++;
	printf("characters = %ld , words = %d, lines = %d\n", n_chars, n_words, n_lines);
	printf("partial lines = %d\n", p_lines);
}

int ecoh_eof()  // 重复输入,直到文件结尾
{
	int ch;
	while (EOF != (ch = getchar()))
	{
		putchar(ch);
	}
}

int file_eof()  // 打开一个文件并显示该文件
{
	int ch;
	FILE* fp;
	char fname[50];  // 存储文件名
	printf("Enter the name of the file: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");  // 打开并读取文件
	if (fp == NULL);  // 如果失败
	{
		printf("Failed to open file. Bey\n");
		exit(1);  //退出程序
	}
	// getc(fp)从打开的文件中获取第一个字符
	while ((ch = getchar()) != EOF)
		putchar(ch);
	fclose(fp);  // 关闭文件
}