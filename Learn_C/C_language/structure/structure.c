#define _CRT_SECURE_NO_WARNINGS
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXTITL1 41
#define MAXAUTL1 31
#define MAXBKS 10  //书籍的最大数量
#define LEN 20
#define FUNDLEN 50
#define NLEN 30
#define SLEN 81
#define N 2
char* s_gets_b(char* st, int n);


struct book    //结构模板:标记是book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	//结构模板结束
};
int book()   // 一本书的图书目录
{
	struct book library;  //把library声明一个book类型的变量
	printf("Please enter the book title.\n");
	s_gets_b(library.title, MAXTITL);  //访问title部分
	printf("Now enter the author.\n");
	s_gets_b(library.author, MAXAUTL);
	printf("Now enter the value.\n");
	scanf("%f", &library.value);
	printf("%s by %s: $%.2f\n", library.title,library.author,library.value);
	printf("%s:\"%s\" ($%.2f)\n", library.author, library.title, library.value);
	printf("Done!\n");
}
char* s_gets_b(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); //查找换行符
		if (find)                // 如果地址不是NULL
			*find = '\0';         //在此处放置一个空字符
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

int manybook()
{
	struct book library[MAXBKS];  //book类型的数组
	int count = 0;
	int index;
	printf("Please enter the book title.\n");
	printf("Please [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets_b(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets_b(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n') //清理输入行
			continue;
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}
	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; ++index)
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
	}
	else
		printf("No books? Too bad.\n");
	/*struct book library[MAXBKS]  把library声明为一个内含MAXBKS个元素的数组,数组的每个元素都是book类型的结构,library是数组名
	*library[0].value 第一个元素与value相关联
	* library[4].title 第五个元素与title相关联
	* 数组下标紧跟在library后面,不是成员名后面 例:library.value[2] 错误  library[2]是结构变量名
	* library[2].title[4] 表示library数组第3个结构变量(library[2]部分)中书名的第5个字符(title[4]部分)
	*/
}

const char* msgs[5] =   //嵌套结构
{
	"  Thank you for the wonderful evening,",
	"You certainly prove that a",
	"is a special kind of guy. We must get together",
	"over a delicious",
	" and have a few laughs"
};
struct names {   //第1个结构
	char first[LEN];
	char last[LEN];
};
struct guy {
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};
int friend(void)  //朋友的基本信息  访问嵌套结构时使用两次点运算符
{
	struct guy fellow = {   // 初始化一个结构变量
		{ "Ewen","Villard"},
		"grilled salmon",
		"personality coach",
		68112.00
	};
	printf("Dear %s,\n\n", fellow.handle.first);
	printf("%s%S.\n", msgs[0], fellow.handle.first);
	printf("%s%s.\n", msgs[1], fellow.job);
	printf("%s\n", msgs[2]);
	printf("%s%s%s.\n", msgs[3], fellow.favfood,msgs[4]);
	if (fellow.income > 150000.0)
		puts("!!");
	else if (fellow.income > 75000.0)
		puts("!");
	else
		puts(".");
	printf("\n%40s%s\n", "", "See you soon");
	printf("%40s%s\n", "", "Shalala");
} 

int friends()
{
	struct guy fellow[2] =
	{
			{   // 初始化一个结构变量
				{ "Ewen","Villard"},
				"grilled salmon",
				"personality coach",
				68112.00
			},
			{
				{"Rodney","Swillbelly"},
				"tripe",
				"tabloid editor",
				432400.00

			}
	};
	struct guy* him;  //这是一个指向结构的指针
	printf("addres #1: % p #2:%p\n", &fellow[0], &fellow[1]);
	him = &fellow[0];
	printf("Pointer #1: %p #2: %p\n", him, him + 1);
	printf("him->income is $%.2f: (*him).income is $%.2f\n", him->income, (*him).income);
	him++;  //指向下一个结构
	printf("him->favfoood is %s: him->handle.last is  %s\n", him->favfood, him->handle.last);
}

struct funds {  // 把结构成员作为参数传递
	char    bank[FUNDLEN];
	double  bankfund;
	char    save[FUNDLEN];
	double  savefund;

};
double sum1(double, double);
int funds1()
{
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's saving and Loan",
		8543.94,
	};
	printf("Stan has a total of $%.2f.\n", sum1(stan.bankfund, stan.savefund));
}
double sum1(double x, double y)  // 两个double类型的数相加
{
	return(x + y);
}

double sum2(const struct funds*);  //参数是一个指针, 传递指向结构的指针
int funds2()
{
	struct funds stan = {
		"Garlic-Melon Bnak",
		4032.27,
		"Lucky's saving anf loan",
		8543.94,
	};
	printf("Stan has a total of $%.2f.\n", sum2(&stan));
}
double sum2(const struct funds* money)
{
	return(money->bankfund + money->savefund);
}

struct namect {  // 使用指向结构的指针双向通信
	char fname[NLEN];
	char lname[NLEN];
	int letter;
};
void getinfo(struct namect*);
void makeinfo(struct namect*);
void showinfo(const struct namect*);
int names1()
{
	struct namect person;
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
}
void getinfo(struct namect* pst)
{
	printf("Please enter your first name.\n");
	s_gets_b(pst->fname, NLEN);
	printf("Please enter your last name.\n");
	s_gets_b(pst->lname, NLEN);
}
void makeinfo(struct namect* pst)
{
	pst->letter = strlen(pst->fname) + strlen(pst->lname);
}
void showinfo(const struct namect* pst)
{
	printf("%s %s, your name contains %d letter.\n", pst->fname, pst->lname, pst->letter);
}

//struct namect getinfo2();  //传递并返回结构,不同的方法实现
//struct namect mekeinfo2(struct namect info);
//void showinfo2(struct namect info);
//int names2()
//{
//	struct namect person;
//	person = getinfo2();
//	person = makeinfo2(person);
//	showinfo2(person);
//	return 0;
//}
//struct namect getinfo2()
//{
//	struct namect temp;
//	printf("Please enter your first name.\n");
//	s_gets_b(temp.fname, NLEN);
//	printf("Please enter your last name.\n");
//	s_get_b(temp.lname, NLEN);
//	return temp;
//}
//struct namect makeinfo2(struct namect info)
//{
//	info.letter = strlen(info.fname) + strlen(info.lname);
//	return info;
//}
//void showinfo2(struct namect info)
//{
//	printf("%s %s ,your name contains %d letters.\n", info.fname, info.lname, info.letter);
//}



struct namect3 {  
	char* fname;
	char* lname;
	int letter;
};
void getinfo3(struct namect*);
void makeinfo3(struct namect*);
void showinfo3(const struct namect*);

int names3()  //使用指针和malloc()分配内存
{
	struct namect person;
	getinfo3(&person);
	makeinfo3(&person);
	showinfo3(&person);
	free(person.fname);
	free(person.lname);
	return 0;
}
void getinfo3(struct namect3* pst)
{
	char temp[SLEN];
	printf("Please enter your first name.\n");
	s_gets_b(temp, SLEN);
	 
	pst->fname = (char*)malloc(strlen(temp) + 1);
	strcpy(pst->fname, temp); //把名拷贝到动态分配的内存中
	printf("Please enter your last name.\n");
	s_gets_b(temp, SLEN);
	pst->lname = (char*)malloc(strlen(temp) + 1);
	strcpy(pst->lname, temp);
	
}
void makeinfo3(struct namect* pst)
{
	pst->letter = strlen(pst->fname) + strlen(pst->lname);
}
void showinfo3(const struct namect* pst)
{
	printf("%s %s,your name contains %d letters.\n", pst->fname, pst->lname, pst->letter);
}

struct book1 {     //复合字面量
	char title[MAXTITL1];
	char author[MAXAUTL1];
	float value;
};
int complit()   //复合字面量可以创建一个结构作为函数的参数或者赋给另一个结构
{
	struct book readfirst;
	int score;
	printf("Enter test score: ");
	scanf("%d", &score);
	if (score >= 84)
		readfirst = (struct book){ "Cirme and Punishment","Fyodor Dostoyevsky",11.25 };
	else
		readfirst = (struct book){ "Mr. Bouncy's Nice Hat","Fred Winsome",5.99 };
	printf("Your assigned reading:\n");
	printf("%s by %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);
}

struct flex {   //伸缩型数组成员
	size_t count;
	double average;
	double scores[]; //伸缩型数组成员

};
void showFlex(const struct flex* p);
int flexmemb()  
{
	struct flex* pf1, * pf2;
	int n = 5;
	int i;
	int tot = 0;
	pf1 = malloc(sizeof(struct flex) + n * sizeof(double));  //为结构和数组分配存储空间
	pf1->count = n;
	for (i = 0; i < n; ++i)
	{
		pf1->scores[i] = 20.0 - i;
		tot += pf1->scores[i];
	}
	pf1->average = tot / n;
	showFlex(pf1);
	n = 9;
	
	pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf2->count = n;
	for (i = 0; i < n; ++i)
	{
		pf2->scores[i] = 20.0 - i / 2.0;
		tot += pf2->scores[i];
	}
	pf2->average = tot / n;
	showFlex(pf2);
	free(pf1);
	free(pf2);
}
void showFlex(const struct flex* p)
{
	int i;
	printf("Scores : ");
	for (i = 0; i < p->count; ++i)
		printf("%g ", p->scores[i]);
	printf("\nAverage: %g\n", p->average);
}


struct funds4 {
	char  bank[FUNDLEN];
	double bankfund;
	char  save[FUNDLEN];
	char  savefund;
};
double sum4(const struct funds money[], int n);
int funds4()
{
	struct funds jones[N] = 
	{
		{
			"Garlic-Melon Bank", 4032.27,"Lucky's Savings and Loan",8543.94
		},
		{
			"Honest Jack's Bank",3620.88,"Party Time Savings",3802.91
		}
	};
	printf("The joneses have a total of $%.2f.\n", sum4(jones, N));
	return 0;
}
double sum4(const struct funds money[], int n)
{
	double total;
	int i;
	for (i = 0, total = 0; i < n; ++i)
	{
		total += money[i].bankfund + money[i].savefund;
	
	}
	return (total);
}


/*已经建立
struct book    //结构模板:标记是book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	//结构模板结束
}
*/
int booksave()   //在文件中保存结构的内容,若文件存在,显示当前内容,允许在文件中添加内容
{
	struct book library[MAXBKS];  //结构数组
	int count = 0;
	int index, filecount;
	FILE* pbooks;
	int size = sizeof(struct book);
	if ((pbooks = fopen("book.dat", "a+b")) == NULL)  //a+b表示以追加和读取的方式打开二进制文件
	{
		fputs("Cant's open book.dat file.\n", stderr); //stderr标准错误输出流
		exit(1);  //终止程序
	}
	rewind(pbooks);  //定位到文件的开始
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("current contents of book.dat:");
		printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("The book.dat file is full.", stderr);
		exit(2);
	}
	puts("Please add new book titles.");
	puts("press [enter] at the start of a line to stop.");
	while (count < MAXBKS && s_gets_b(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		s_gets_b(library[count].author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &library[count++].value);  //"count自增1，以准备存储下一本书的信息
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts("Enter the next title.");
			
	}
	if (count > 0)
	{
		puts("Here is the list of your books:");
		for (index = 0; index < count; ++index)
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("No books? too bad.\n");
	puts("Bey.\n");
	fclose(pbooks);
}




	