﻿// day25_函数的声明.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
void f(void); //函数声明,分号不能丢掉


void g(void)
{
    f();
}
int main()
{
    g();

    return 0;
}

void f(void)
{
    printf("哈哈\n");
}


//  函数调用和函数顺序: 如果函数调用写在函数定义的前面,则必须加函数前置声明
//                  函数前置声明  :  1) 告诉编译器即将可能出现若干个字母代表的是一个函数
//                                 2) 告诉编译器即将可能出现若干个字母所代表的函数的形参和返回值的具体情况
//                                 3) 函数声明是一个语句,末尾必须要加分号
//                                 4) 对库函数的声明是通过# include<库函数所在的文件名.h>来实现的 例子:printf函数
