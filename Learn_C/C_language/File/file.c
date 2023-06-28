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
int reducto(int argc, char * argv[])   //���ļ�ѹ����ԭ����1/3,�����ļ����뵽��һ���ļ���
{
	FILE* in, * out;  //��������ָ��FILE��ָ��
	int ch;
	char name[LEN]; // �洢����ļ���
	int count = 0;

	//��������в���
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	//��������
	if (in = fopen(argv[1], "r") == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"s\"\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	//�������
	strncpy(name, argv[1], LEN - 5);  //�����ļ���
	name[LEN - 5] = '\0';
	strcat(name, ".red");  //���ļ��������.red
	if ((out = fopen(name, "w")) == NULL) // ��д��ģʽ���ļ�
	{
		fprintf(stderr, "Can't creat output file.\n");
		exit(3);
	}
	//��������
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);  //��ӡ�����ַ��еĵ�һ���ַ�
	// ��β����
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Eorror in closing files.\n");
}

int addaword()  // ʹ��fprintf fscanf rewind
{
	FILE* fp;
	char words[MAX];
	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");  //fprintf����Ҫ�õ�һ������ָ����������ļ�
		exit(EXIT_FAILURE);
	}
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);
	puts("File contnts:");
	rewind(fp);  //���ص��ļ���ʼ��
	while (fscanf(fp, "%s", words) == 1)
		puts(words);
	puts("Done.");
	if (fclose(fp) != 0)
		fprintf(stderr, "Eorror closing file\n");
}

int reverse()   //������ʾ�ļ�������
{
	char file[SLEN];
	char ch;
	FILE* fp;
	long count, last;
	puts("Enter the name of the file to be processed:");
	scanf("%80s", file);
	if ((fp = fopen(file, "rb")) == NULL)  //ֻ��ģʽ
	{
		printf("reverse cant't open %s\n", file);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END); //��λ���ļ�ĩβ fseek������fopen�򿪵��ļ���ֱ���ƶ��������ֽڴ�,��3������,����int���͵�ֵ,��������0,���󷵻�-1
	last = ftell(fp); //ftell��������һ��long���͵�ֵ,���ص��ǲ���ָ���ļ��ĵ�ǰλ�þ��ļ���ʼ�����ֽ���
	for (count = 1L; count <= last; ++count)
	{
		fseek(fp, -count, SEEK_END); //����
		ch = gets(fp); 
		if (ch != CNTL_Z && ch != '\r')  //MS-DOS�ļ�
			putchar(ch);
	}
	putchar('\n');
	fclose(fp);
	/*  fseek(fp,0L,SEEK_SET) ��λ���ļ���ʼ��
		fseek(fp, 10L, SEEK_SET) ��λ���ļ��еĵ�10���ֽ�
		fseek(fp, 2L, SEEK_CUR) �ӵ�ǰλ��ǰ��2���ֽ�
		fseek(fp, 0L, SEEK_END) ��λ���ļ���β��
		fseek(fp, -10L, SEEK_END) ���ļ���β������10���ֽ�*/
}

int append()  //���ļ����ӵ���һ���ļ���ĩβ
{
	FILE* fa, * fs;  //faָ��Ŀ���ļ�,fsָ��Դ�ļ�
	int files = 0;   // �������ļ�����
	char file_app[SLEN];  //Ŀ���ļ���
	char file_src[SLEN];  //Դ�ļ���
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
	static char temp[BUFSIZE];  //ֻ����һ��
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
		find = strchr(st, '\n'); //���һ��з�
		if (find)                // �����ַ����NULL
			*find = '\0';         //�ڴ˴�����һ�����ַ�
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}


int randbin()  //�ö�����I/O�����������
{
	double numbers[ARSIZE];
	double value;
	const char* file = "number.dat";
	int i;
	long pos;
	FILE* iofile;
	//����һ��double����
	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	//���Դ��ļ�
	if ((iofile = fopen(file, "wb")) == NULL)
	{
		fprintf(stderr, "Could not open %s for output.\n", file);
		exit(EXIT_FAILURE);
	}
	//�Զ����Ƹ�ʽ������д���ļ�
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((iofile = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "Could not open %s for random access.\n", file);
		exit(EXIT_FAILURE);
	}
	//���ļ��ж�ȡѡ��������
	printf("Enter an index in the range 0-%d.\n",ARSIZE - 1);
	while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof(double);  //����ƫ����
		fseek(iofile, pos, SEEK_SET);  //��λ���˴�
		fread(&value, sizeof(double), 1, iofile);
		printf("The value there is %f.\n", value);
		printf("Next index (out of range to quit):\n");
	}
	fclose(iofile);
	puts("Bey.\n");
}