#define _CRT_SECURE_NO_WARNINGS
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define MAX 41
#define CNTL_Z '\032'
#define SLEN 81
#define BUFSIZE 4096
#define ARSIZE 1000



void append1(FILE* source, FILE* dest);
char* s_gets12(char* st, int n);
int reducto(int argc, char * argv[])   //把文件压缩成原来的1/3,并把文件放入到另一个文件中
{
	FILE* in, * out;  //声明两个指向FILE的指针
	int ch;
	char name[LEN]; // 存储输出文件名
	int count = 0;

	//检查命令行参数
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	//设置输入
	if (in = fopen(argv[1], "r") == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"s\"\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	//设置输出
	strncpy(name, argv[1], LEN - 5);  //拷贝文件名
	name[LEN - 5] = '\0';
	strcat(name, ".red");  //在文件名后添加.red
	if ((out = fopen(name, "w")) == NULL) // 以写的模式打开文件
	{
		fprintf(stderr, "Can't creat output file.\n");
		exit(3);
	}
	//拷贝数据
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);  //打印三个字符中的第一个字符
	// 收尾工作
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Eorror in closing files.\n");
}

int addaword()  // 使用fprintf fscanf rewind
{
	FILE* fp;
	char words[MAX];
	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");  //fprintf函数要用第一个参数指定待处理的文件
		exit(EXIT_FAILURE);
	}
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);
	puts("File contnts:");
	rewind(fp);  //返回到文件开始处
	while (fscanf(fp, "%s", words) == 1)
		puts(words);
	puts("Done.");
	if (fclose(fp) != 0)
		fprintf(stderr, "Eorror closing file\n");
}

int reverse()   //倒叙显示文件的内容
{
	char file[SLEN];
	char ch;
	FILE* fp;
	long count, last;
	puts("Enter the name of the file to be processed:");
	scanf("%80s", file);
	if ((fp = fopen(file, "rb")) == NULL)  //只读模式
	{
		printf("reverse cant't open %s\n", file);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END); //定位到文件末尾 fseek函数在fopen打开的文件中直接移动到任意字节处,由3个参数,返回int类型的值,正常返回0,错误返回-1
	last = ftell(fp); //ftell函数返回一个long类型的值,返回的是参数指向文件的当前位置距文件开始处的字节数
	for (count = 1L; count <= last; ++count)
	{
		fseek(fp, -count, SEEK_END); //回退
		ch = gets(fp); 
		if (ch != CNTL_Z && ch != '\r')  //MS-DOS文件
			putchar(ch);
	}
	putchar('\n');
	fclose(fp);
	/*  fseek(fp,0L,SEEK_SET) 定位至文件开始处
		fseek(fp, 10L, SEEK_SET) 定位至文件中的第10个字节
		fseek(fp, 2L, SEEK_CUR) 从当前位置前移2个字节
		fseek(fp, 0L, SEEK_END) 定位至文件结尾处
		fseek(fp, -10L, SEEK_END) 从文件结尾处回退10个字节*/
}

int append()  //把文件附加到另一个文件的末尾
{
	FILE* fa, * fs;  //fa指向目标文件,fs指向源文件
	int files = 0;   // 附件的文件数量
	char file_app[SLEN];  //目标文件名
	char file_src[SLEN];  //源文件名
	int ch;
	puts("Enter name of destination file:");
	s_gets(file_app, SLEN);
	if ((fa = fopen(file_app, "a+")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", file_app);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	puts("Enter name of first soure file (empty line to quit):");
	while (s_gets(file_src, SLEN) && file_src[0] != '\0')
	{
		if (strcmp(file_src, file_app == 0))
			fputs("Can't append file to itself\n", stderr);
		else if ((fs = fopen(file_src,"r")) == NULL)
			fprintf(stderr,"Can't open %s\n",file_src);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can't create input buffer \n", stderr);
				continue;
			}
			append1(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n", file_src);
			if(ferror(fa)!=0)
				printf(stderr, "Error in writing file %s.\n", file_app);
			fclose(fs);
			files++;
			printf("File %s appened.\n", file_src);
			puts("Next file (empty line to quit):");
		}
	}
	printf("Done appending.%d files appened.\n", files);
	rewind(fa);
	printf("%s contents:\n", file_app);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("Done displaying.");
	fclose(fa);
}
void append1(FILE* source, FILE* dest)
{
	size_t bytes;
	static char temp[BUFSIZE];  //只分配一次
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}
char* s_gets12(char* st, int n)
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


int randbin()  //用二进制I/O进行随机访问
{
	double numbers[ARSIZE];
	double value;
	const char* file = "number.dat";
	int i;
	long pos;
	FILE* iofile;
	//创建一组double类型
	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	//尝试打开文件
	if ((iofile = fopen(file, "wb")) == NULL)
	{
		fprintf(stderr, "Could not open %s for output.\n", file);
		exit(EXIT_FAILURE);
	}
	//以二进制格式把数据写入文件
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((iofile = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "Could not open %s for random access.\n", file);
		exit(EXIT_FAILURE);
	}
	//从文件中读取选定的内容
	printf("Enter an index in the range 0-%d.\n",ARSIZE - 1);
	while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof(double);  //计算偏移量
		fseek(iofile, pos, SEEK_SET);  //定位到此处
		fread(&value, sizeof(double), 1, iofile);
		printf("The value there is %f.\n", value);
		printf("Next index (out of range to quit):\n");
	}
	fclose(iofile);
	puts("Bey.\n");
}