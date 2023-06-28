// day13_continue用法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 用于跳过本次循环余下的语句,转去判断是否需要执行下次循环

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int i = 0;
    int j = 0;
    char ch;
    scanf("%d", &i);
    printf("i = %d\n", i);

    while (ch = getchar() != '\n')  //getchar()意思是要求用户输入字符,获取字符;      !和=就是 !=
      continue;

    scanf("%d", &j);
    printf("j = %d\n", j);

    return 0;

}

/*
for (1; 2; 3)
{
    A;
    B;
    continue;//如果执行该语句,则执行语句3,不会执行cd语句
    C;
    D;
}
*/