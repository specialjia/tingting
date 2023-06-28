// day47_动态内存和静态内存的比较.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void f(int**)
{
    // *q就是p

}

void g()
{
    int i = 10;
    int* p = &i;
    f(&p);  // p是int *类型,,  &p是int**类型

}


int main()
{

    g();
    return 0;
}














/*
int main()
{
    int i = 10;
    int* p = &i;
    int** q = &p;
    int*** r = &q;
    ***r = i;
  //  r = &p;  error, r是int***类型,r只能存放int**类型变量的地址
    printf("i = %d\n", ***r);

    return 0;
}
*/






/* 
* 
* 
* 
* 
* 
* 
* 
*/