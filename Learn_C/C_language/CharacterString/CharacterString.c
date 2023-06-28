#define _CRT_SECURE_NO_WARNINGS
#include "CharacterString.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MSG "I am a symbolic string constant."
#define MAXLENGTH 81
#define MSG1 "I'm special"
#define SLEN 40
#define LIM 5
#define STLEN 81
#define STLEN1 14
#define STLEN2 10
#define  DEF "I am a #define string."
#define SIZE 80
#define SIZE1 30
#define BUGSZIE 13
#define ANSWER "Grant"
#define SIZE2 40
#define LIM1 10
#define STOP "quit"
#define LISTSIZE 6
#define SIZE3 40
#define LIM3 5
#define MAX 20



/*  char car[10] = "Tata"
* �� car == &car[0], *car == 'T', *(car+1) == car[1] == 'a'  

*/

int string()
{
	char words[MAXLENGTH] = "I am a string in an array.";
	const char* pt1 = "Something is pointing at me.";
	puts("Here are some strings:");
	puts(MSG);                                     // puts()�������ֻ��ʾ�ַ���,���Զ���ĩβ���ϻ��з�
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);
}

int address()  //�ַ����ĵ�ַ
{
	char ar[] = MSG;
	const char* pt = MSG;
	printf("address of \"I'm special\": %p\n", "I'm special");
	printf("        address ar: %p\n",ar);
	printf("         address pt: %p\n", pt);
	printf("        address MSG: %p\n", MSG);
	printf("address of \"I'm special\": %p\n", "I'm special");
}

int arrchar()  //ָ������,�ַ�������
{
	const char* mytalents[LIM] = {
		"addding numbers swiftly",
		"Multiplying accurately",
		"Stashing data",
		"Following instructions to the letter",
		"Understanding the C language"
	};
	char yourtalents[LIM][SLEN] = {
		"Walking in a straight line",
		"Sleeping", "Watching television",
		"malling letters", "Reading email"
	};
	int i;
	puts("Let's compare talents.");
	printf("%-36s %-25s\n", "My Talents", "Your Talents");
	for (i = 0; i < LIM; ++i)
	{
		printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
	}
	printf("\nsizeof(mytalents): %zd, sizeof(yourtalents): %zd\n", sizeof(mytalents), sizeof(yourtalents));

}

int p_and_s()  //ָ�뼰�ַ���
{
	const char* mesg = "Don't be a fool!";
	const char* copy;
	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
	printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);
}
int getsputs()  // gets puts ��ʹ��   ������ʹ�� �������
{
	char words[STLEN];  
	puts("Enter a string,please.");
	gets(words); //�����÷�
	printf("Your string twice:\n");
	printf("%s\n", words);
	puts(words);
	puts("Done.");
}

  // �ַ�������
int fgets1()
{
	char words[STLEN1];
	puts("Enter a string,please.");
	fgets(words, STLEN1, stdin);  
	printf("Your string twice (puts(),then fputs()):\n");
	puts(words);          // fputs�����������ַ���ĩβ���ϻ��з�, ����puts������. 
	fputs(words, stdout); //fputs�����ڶ�������Ҫָ��д����ļ�,Ӧʹ��stdout(��׼���)��Ϊ����  ��洢��������,������Ŷ�ȡ
	puts("Enter another string,please.");
	fgets(words, STLEN1, stdin);
	printf("Your string twice (puts(),fputs()):\n");
	puts(words);
	fputs(words, stdout);
	puts("Done.");

}

int fgets2()
{
	char words[STLEN2];
	puts("Enter string (empty line to quit):");
	while (NULL != fgets(words, STLEN2, stdin) && words[0] != '\n')  //  fgets����һ�ζ���STLEN2-1���ַ�,��9��
	{
		fputs(words, stdout);
	}
	puts("Done.");
}

int fgets3()
{
	char words[STLEN2];
	int i;
	puts("Enter strings (empty line to quit):");
	while (NULL != fgets(words, STLEN2, stdin) && words[0] != '\n')
	{
		i = 0;
		while (words[i] != '\n' && words[i] != '\0')
			++i;
		if (words[i] == '\n')
			words[i] = '\0';
		else   // ���words[i] == '\0'��ִ���ⲿ�ֵĴ���     
			while (getchar() != '\n')
				continue;
		puts(words);

	}
	puts("Done.");     /* fgets��ȡһ��������,�������������� */
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)  //ret_val != NULL
	{
		while (st[i] != '\n' && st[i] != '\0')
			++i;
		if (st[i] = '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
}
int scan_str()   //ʹ��scanf
{
	char name1[11], name2[11];
	int count;
	printf("Please enter 2 names.\n");
	count = scanf("%5s %10s", name1, name2);
	printf("I read the %d names %s and %s.\n", count, name1, name2);
}

//�ַ������
int put_out()  // ʹ��puts����
{
	char str1[80] = "An array was initialized to me.";
	const char* str2 = "A pointer was initialzed to me.";
	puts("I'm an argument to puts().");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[5]);
	puts(str2 + 4);
}

void put1(const char* string);
int put2(const char* string);
int put_put()  //�û��Զ����������
{
	put1("If I'd as much money");
	put1(" as I could spend,\n");
	printf("I count %d characters.\n", put2("I never would cry old chairs to mend."));

}
void put1(const char* string)
{
	while (*string)  // ��*string != '\0' ��ͬ
	{
		putchar(*string++);
	}
}
int put2(const char* string)
{
	int count = 0;
	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');
	return (count);
}

void fit(char* string, unsigned int size)
{
	if (strlen(string) > size)
		string[size] = '\0';
}
int test_fit()   //ʹ�������ַ������ȵĺ���
{
	char mesg[] = "Things should be as simple as possible,but not simper.";
	puts(mesg);
	fit(mesg, 38);
	puts(mesg);
	puts("let's look at some more of the string.");
	puts(mesg + 39);  //mesg + 39 ��mesg[39]�ĵ�ַ

}


char* s_gets1(char* st, int n);
int str_cat()   //ƴ�������ַ���,�����޷�����һ�������Ƿ����ݵ�2���ַ���
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	puts("What is your favorite flower?");
	if (s_gets1(flower, SIZE))
	{
		strcat(flower, addon);
		puts(flower);
		puts(addon);
	}
	else
		puts("End of file encountered!");   //�ļ��Ľ�β
	puts("Bye!");
}
char* s_gets1(char* st, int n)
{
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			++i;
		if (st[i] = '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}


int join_cnk()  // ƴ�������ַ���,������һ������Ĵ�С
{
	char flower[SIZE];
	char addon[] = "s semll like old shoes.";
	char bug[BUGSZIE];
	int available;  //���ڱ�ʾ������ӵ�����ַ���
	puts("What is your favorite flower?");
	s_gets(flower, SIZE1);
	if (strlen(flower) + strlen(addon) + 1 <= SIZE1)
		strcat(flower, addon);
	puts("What is your favorite bug?");
	s_gets(bug, BUGSZIE);
	available = BUGSZIE - strlen(bug) - 1;
	strcat(bug, addon, available);
	puts(bug);
}

int compare()  // strcmp������ʹ��,�Ƚϵ����ַ��� �����������鼰ĳ����ĸ,֪�����ֲ�ͬ���ַ�Ϊֹ
{
	char try[SIZE2];
	puts("Who is buried in Grant's tomb?");
	s_gets(try, SIZE2);
	while (strcmp(try, ANSWER != 0))
	{
		puts("No, that's wrong. Try again.");
		s_gets(try, SIZE2);
	}
	puts("That's right!");
}

int quit_chk()   //��strcmp�����������Ƿ�ֹͣ,
{
	char input[LIM1][SIZE];
	int ct = 0;
	printf("Enter up to %d lines (type quit to quit):\n", LIM1);
	while (ct != LIM1 && s_gets(input[ct], SIZE) != NULL && strcmp(input[ct], STOP)!= 0)
	{
		++ct;
	}
	printf("%d strings entered\n", ct);
}

int strncmp1()  // strncmp�������ԱȽ��ַ���ͬ�ĵط�,����ֻ�Ƚϵ�3������ָ�����ַ���
{
	const char* list[LISTSIZE] =
	{
		"astronomy","astounding",
		"astrophysics","ostracize",
		"asterism","astrophobia"
	};
	int count = 0;
	int i;
	for (i = 0; i < LISTSIZE; ++i)
		if(strncmp(list[i],"astro",5) == 0)
		{
			printf("Found: %s\n", list[i]);
			++count;
		}
	printf("The list contained %d words begining with astro.\n", count);
}

int strcpy1()   //�ַ�����ֵ����
{
	char qwords[LIM3][SIZE3];
	char temp[SIZE3];
	int i = 0;
	printf("Enter %d words beginning with q :\n", LIM3);
	while (i < LIM3 && s_gets(temp, SIZE3))
	{
		if (temp[0] != 'q')
		{
			printf("%s doesn't begin with q!\n", temp);
		}
		else
		{
			strcpy(qwords[i], temp);
			++i;
		}
	}
	puts("Here are the words accepted:");
	for (i = 0; i < LIM3; ++i)
	{
		puts(qwords[i]);
	}
}

int forma1()  // ��ʽ���ַ���
{
	char first[MAX];
	char last[MAX];
	char forma1[2 * MAX + 10];
	double prize;
	puts("Enter your first name:");
	s_gets(first, MAX);
	puts("Enter your last name:");
	s_gets(last, MAX);
	puts("Enter your prize money:");
	scanf("%lf", &prize);
	sprintf(forma1, "%s,%-19s: $%6.2f\n", last, first, prize); //sprintf�ǰ�����д���ַ���
	puts(forma1);
}

