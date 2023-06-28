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
#define PSQR(x) printf("The square of "#x" is %d.\n",((x)*(x)))  //#x是转换成字符串"x"的形参名.这个过程被称为字符串化
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n",x ## n)
#define PR(X,...) printf("Message "#X": " __VA_ARGS__)   //数量可变的参数,省略号只能代替最后的宏参数
#define LIMIT 4
#define JUST_CHECKING
#define MYTYPE(X) _Generic((X),int: "int", float: "float", double: "double", default: "other")
#define RAD_TO_DEG (180/(4*atan(1)))
#define SQRT(X) _Generic((X),long double:sqrtl, default:sqrt, float:sqrtf)(X)  // 泛型平方根函数
#define SIN(X) _Generic((X),long double:sinl((X)/RAD_TO_DEG), default:sin((X)/RAD_TO_DEG), float:sinf((X)/RAD_TO_DEG) 
// 泛型正弦函数,调度的单位为度
#define NUM 40



void why_me();
int mac_arg()   //带参数的宏
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
	PR(SQUARE(x+2));  //预处理器不计算 不求值,只替换字符序列  x*x变成 x+2*x+2 ,输出结果是17
	printf("Evaluating 100/SQUARE(2): ");
	PR(100 / SQUARE(2));  //100 / SQUARE(2)变成 100/2*2,输入结果是100
	printf("x is %d.\n", x);
	printf("Evaluating SQUARE(++x): ");
	PR(SQUARE(++x));  //++x*++x
	printf("After incrementing, x is %x.\n", x);
}

int subst()  //在字符串中替换  #运算符
{
	int y = 5;
	PSQR(y);
	PSQR(2 + 4);
}

int glue()   //使用##运算符 预处理器黏合剂
{
	int XNAME(1) = 14;  // 变成intx1 = 14;
	int XNAME(2) = 20;
	int x3 = 30;
	PRINT_XN(1);     //变成printf(" x1 = %d\n", x1)
	PRINT_XN(2);
	PRINT_XN(3);
}

int variadic()  //变参宏
{
	double x = 48;
	double y;
	y = sqrt(x);
	PR(1, "x = %g\n", x);
	PR(2, "x = %.2f, y = %.4f\n", x, y);
}

int ifdef()  //使用条件编译
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

int predef()   //预定义宏和预定义标识符
{
	printf("The file is %s.\n", __FILE__);
	printf("The date is %s.\n", __DATE__);
	printf("The time is %s.\n", __TIME__);
	/*printf("The version is %ld.\n", __STDC_VERSION__);*/
	printf("This is line %d.\n", __LINE__);
	printf("This function is %s\n", __func__);  //预定义标识符
	why_me();
}
void why_me()
{
	printf("This function is %s\n", __func__);
	printf("This is line %d.\n", __LINE__);
}

int  mytype()  //泛型选择标签
{
	int d = 5;
	/*printf("%s\n", MYTYPE(d));   
	printf("%s\n", MYTYPE(2.0 * d));
	printf("%s\n", MYTYPE(3L));
	printf("%s\n", MYTYPE(&d));*/
}

typedef struct polar_v {   //把直角坐标转换为极坐标
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

int generic()  //定义泛型宏
{
	float x = 45.0f;
	double xx = 45.0;
	//long double xxx = 45.0L;
	//long double y = SQRT(x);
	//long double yy = SQRT(xx);
	//long double yyy = SQRT(xxx);
	//printf("%.17Lf\n", y);  //匹配float
	//printf("%.17Lf\n", yy);  //匹配default
	//printf("%.17Lf\n", y);  //匹配long double
	//int i = 45;
	//yy = SQRT(i);
	//printf("%.17Lf\n", yy);
	//yyy = SIN(xxx);
	//printf("%.17Lf\n", yyy);
}


void sign_off(void);
void too_bad(void);
int byebye()  //atexit()示例
{
	int n;
	atexit(sign_off);   //注册sing_off函数
	puts("Enter an integer:");
	if (scanf("%d", &n) != 1)
	{
		puts("That's no integer!");
		atexit(too_bad);  //注册too_bad函数
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
int qsorter()  // 用qsort()排序一组数字
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
		ar[index] = (double)rand() / ((double)rand() + 0.1);  //rand函数函数来生成随机整，两数相除得到一个随机的浮点数
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
{    //要使用指向double的指针来访问这两个值
	const double* a1 = (const double*)p1;
	const double* a2 = (const double*)p2;
	if (*a1 < *a2)
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		return 1;
}

int assert1()  //断言库
{
	double x;
	double y;
	double z;
	puts("Enter a pair of numbers(0 0 to quit)");
	while (scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0))
	{
		z = x * x - y * y; //应该用+
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