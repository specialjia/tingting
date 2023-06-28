#define _CRT_SECURE_NO_WARNINGS
#include "Preprocessor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#define SQUARE(X) X*X
#define PR(X)  printf("The result is %d.\n",X)
#define PSQR(x) printf("The square of "#x" is %d.\n",((x)*(x)))  //#x��ת�����ַ���"x"���β���.������̱���Ϊ�ַ�����
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n",x ## n)
#define PR(X,...) printf("Message "#X": " __VA_ARGS__)   //�����ɱ�Ĳ���,ʡ�Ժ�ֻ�ܴ������ĺ����
#define LIMIT 4
#define JUST_CHECKING
#define MYTYPE(X) _Generic((X),int: "int", float: "float", double: "double", default: "other")
#define RAD_TO_DEG (180/(4*atan(1)))
#define SQRT(X) _Generic((X),long double:sqrtl, default:sqrt, float:sqrtf)(X)  // ����ƽ��������
#define SIN(X) _Generic((X),long double:sinl((X)/RAD_TO_DEG), default:sin((X)/RAD_TO_DEG), float:sinf((X)/RAD_TO_DEG) 
// �������Һ���,���ȵĵ�λΪ��
#define NUM 40



void why_me();
int mac_arg()   //�������ĺ�
{
	int x = 5;
	int z;
	printf("x = %d\n", x);
	z = SQUARE(x);
	printf("Evaluating SQUARE(x): ");
	PR(z);
	z = SQUARE(2);
	printf("Evaluating SQUARE(2): ");
	PR(z);
	printf("Evaluating SQUARE(x+2): ");
	PR(SQUARE(x+2));  //Ԥ������������ ����ֵ,ֻ�滻�ַ�����  x*x��� x+2*x+2 ,��������17
	printf("Evaluating 100/SQUARE(2): ");
	PR(100 / SQUARE(2));  //100 / SQUARE(2)��� 100/2*2,��������100
	printf("x is %d.\n", x);
	printf("Evaluating SQUARE(++x): ");
	PR(SQUARE(++x));  //++x*++x
	printf("After incrementing, x is %x.\n", x);
}

int subst()  //���ַ������滻  #�����
{
	int y = 5;
	PSQR(y);
	PSQR(2 + 4);
}

int glue()   //ʹ��##����� Ԥ�������ϼ�
{
	int XNAME(1) = 14;  // ���intx1 = 14;
	int XNAME(2) = 20;
	int x3 = 30;
	PRINT_XN(1);     //���printf(" x1 = %d\n", x1)
	PRINT_XN(2);
	PRINT_XN(3);
}

int variadic()  //��κ�
{
	double x = 48;
	double y;
	y = sqrt(x);
	PR(1, "x = %g\n", x);
	PR(2, "x = %.2f, y = %.4f\n", x, y);
}

int ifdef()  //ʹ����������
{
	int i;
	int total = 0;
	for (i = 1; i <= LIMIT; i++)
	{
		total += 2 * i * i + 1;
#ifdef JUST_CHECKING
		printf("i=%d, runing total = %d\n", i, total);
#endif
	}
	printf("Grand total = %d\n", total);
}

int predef()   //Ԥ������Ԥ�����ʶ��
{
	printf("The file is %s.\n", __FILE__);
	printf("The date is %s.\n", __DATE__);
	printf("The time is %s.\n", __TIME__);
	/*printf("The version is %ld.\n", __STDC_VERSION__);*/
	printf("This is line %d.\n", __LINE__);
	printf("This function is %s\n", __func__);  //Ԥ�����ʶ��
	why_me();
}
void why_me()
{
	printf("This function is %s\n", __func__);
	printf("This is line %d.\n", __LINE__);
}

int  mytype()  //����ѡ���ǩ
{
	int d = 5;
	/*printf("%s\n", MYTYPE(d));   
	printf("%s\n", MYTYPE(2.0 * d));
	printf("%s\n", MYTYPE(3L));
	printf("%s\n", MYTYPE(&d));*/
}

typedef struct polar_v {   //��ֱ������ת��Ϊ������
	double magnitude;
	double angle;
}Polar_V;
typedef struct rect_V {
	double x;
	double y;
}Rect_V;
Polar_V rect_to_polar(Rect_V rv)
{
	Polar_V pv;
	pv.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);
	if (pv.magnitude == 0)
		pv.angle = 0.0;
	else
		pv.angle = RAD_TO_DEG * atan2(rv.y, rv.x);
	return pv;
}
int rect_pol()
{
	Rect_V input;
	Polar_V result;
	puts("Enter x and y coordinates; enter q to quit:");
	while (scanf("%lf %lf", &input.x, &input.y) == 2)
	{
		result = rect_to_polar(input);
		printf("magnitude= %0.2f,angle = %0.2f\n",result.magnitude,result.angle);
	}
	puts("Bye.");
}

int generic()  //���巺�ͺ�
{
	float x = 45.0f;
	double xx = 45.0;
	//long double xxx = 45.0L;
	//long double y = SQRT(x);
	//long double yy = SQRT(xx);
	//long double yyy = SQRT(xxx);
	//printf("%.17Lf\n", y);  //ƥ��float
	//printf("%.17Lf\n", yy);  //ƥ��default
	//printf("%.17Lf\n", y);  //ƥ��long double
	//int i = 45;
	//yy = SQRT(i);
	//printf("%.17Lf\n", yy);
	//yyy = SIN(xxx);
	//printf("%.17Lf\n", yyy);
}


void sign_off(void);
void too_bad(void);
int byebye()  //atexit()ʾ��
{
	int n;
	atexit(sign_off);   //ע��sing_off����
	puts("Enter an integer:");
	if (scanf("%d", &n) != 1)
	{
		puts("That's no integer!");
		atexit(too_bad);  //ע��too_bad����
		exit(EXIT_FAILURE);
	}
	printf("%d is %s.\n", n, (n % 2 == 0) ? "even" : "odd");
}
void sign_off(void)
{
	puts("Thus terminates another magnificent program from");
	puts("SeeSaw Software!");
}
void too_bad(void)
{
	puts("SeeSaw Software extends its heartfelt condolences");
	puts("to you upon the failure of your program.");
}


void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
int mycomp(const void* p1, const void* p2);
int qsorter()  // ��qsort()����һ������
{
	double vals[NUM];
	fillarray(vals,NUM);
	puts("random list:");
	showarray(vals, NUM);
	qsort(vals, NUM, sizeof(double), mycomp);
	puts("\nSorted list:");
	showarray(vals, NUM);
	return 0;
}
void fillarray(double ar[], int n)
{
	int index;
	for (index = 0; index < n; ++index)
	{
		ar[index] = (double)rand() / ((double)rand() + 0.1);  //rand�����������������������������õ�һ������ĸ�����
	}
}
void showarray(const double ar[], int n)
{
	int index;
	for (index = 0; index < n; ++index)
	{
		printf("%9.4f", ar[index]);
		if (index % 6 == 5)
			putchar('\n');
	}
	if (index % 6 != 0)
		putchar('\n');
}
int mycomp(const void* p1, const void* p2)
{    //Ҫʹ��ָ��double��ָ��������������ֵ
	const double* a1 = (const double*)p1;
	const double* a2 = (const double*)p2;
	if (*a1 < *a2)
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		return 1;
}

int assert1()  //���Կ�
{
	double x;
	double y;
	double z;
	puts("Enter a pair of numbers(0 0 to quit)");
	while (scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0))
	{
		z = x * x - y * y; //Ӧ����+
		assert(z >= 0);
		printf("answer is %f\n", sqrt(z));
		puts("Next pair of number: ");
	}
	puts("Dode.");
}

//
//int atatasrt()
//{
//	_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
//	puts("char is 16 bits.");
//	return 0;
//}