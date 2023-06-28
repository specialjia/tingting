// day31_全局变量与局部变量命名冲突的问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
int i = 99;

void f(int i)
{
    printf("i = %d\n", i);

}

int main()
{
    f(8);

    return 0;
}

//在一个函数内部如果定义的局部变量名字的名字和全局变量一样时,局部变量会屏蔽全局变量