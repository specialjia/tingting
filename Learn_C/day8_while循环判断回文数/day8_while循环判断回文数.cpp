// day8_while循环判断回文数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 回文数:正着写倒着写都是一样的 如121 1221,12321

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int val;  //存放待判断数字
    int m;
    int sum = 0;
    printf("请输入你需要判断的数字:  ");
    scanf("%d", &val);

    m = val;
    while (m)  // m非零,m成立
    {
        sum = sum * 10 + m % 10; // m取余数
        m /= 10;   //等价于m=m/10,结果为m除以10的商(整数,非小数)

    }
    if (sum == val)
        printf("Yes!\n");
    else
        printf("No!\n");

    return 0;

}

//从键盘输入一个数字,如果是回文数,则返回yes,否则返回no