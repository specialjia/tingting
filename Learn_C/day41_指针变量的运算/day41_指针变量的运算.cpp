// day41_指针变量的运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int  i = 5;
    int j = 10;
    int* p = &i;
    int* q = &j;
    int a[5];
    p = &a[1];
    q = &a[4];
    printf("p和q所指向的单元相隔%d个单元\n", q - p);

    //  p-q没有实际意义

    return 0;
}

//  运算只能相减: 如果两个指针变量指向的是同一块连续空间的不同存储单元则这两个指针变量才可以相减