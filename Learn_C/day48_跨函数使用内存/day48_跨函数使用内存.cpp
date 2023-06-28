// day48_跨函数使用内存.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <malloc.h>
//动态内存可以跨函数使用

void f(int** q)
{
    *q = (int*)malloc(sizeof(int)); // sizeof(数据类型),返回值是该数据类型所占的字节
    //q = 5;  error
    //*q = 5;  p = 5, p是变量
     **q = 5; //*p =5  以p为内容的的四个字节
}


int main()
{
    int* p;
    f(&p);
    printf("%d\n", *p);


    return 0;
}







/*
// 静态变量不能跨函数使用
void f(int** q) // q是个指针变量,无论q是什么类型的指针变量,都占四个字节
{
    int i = 5;
    *q = &i;  //  *q等价于p  q和**q都不等价于p

}

int main()
{
    int* p;
    f(&p);
    printf("%d\n", *p);  // 本语句语法没有问题,但是逻辑有问题


    return 0;
}
*/



// 