// day10_do while循环.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 主要用于人机交互

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    double a, b, c;
    double delta;
    double x1, x2;
    char ch;    // 是一个字符串
    do 
    {
        printf("请输入一元二次方程的三个系数: \n");
        printf("a = ");
        scanf("%lf", &a);

        printf("b = ");
        scanf("%lf", &b);

        printf("c = ");
        scanf("%lf", &c);

        delta = b * b - 4 * a * c;

        if (delta > 0)
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("有两个解, x1 = %lf, x2 = %lf\n", x1, x2);
        }

        else if (delta = 0)
        {
            x1 = -b / (2 * a);
            printf("有唯一解, x1 = x2 = %lf\n", x1, x2);
        }

        else
        {
            printf("无实数解!\n");
        }
        printf("您想继续吗?(Y/N): ");
        scanf(" %c", &ch);  // %c前面必须要加一个空格
    } while (1);

    return 0;
}
