// day50_结构体赋值及初始化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
struct Student
{
    int age;
    float score;
    char sex;

 };

int main()
{
    struct Student st = { 80, 66.6, 'F' };  //初始化  定义的同时赋初值
    struct Student st2 = {10, 88, 'F'};  // 也可以分开赋值了
    //st2.age = 10;
    //st2.score = 88;
    //st2.sex = 'F';

    printf("%d %f %c\n", st.age, st.score, st.sex);
    printf("%d %f %c\n", st2.age, st2.score, st2.sex);


    return 0;

}

/* 怎么使用结构体变量 
       赋值和初始化: 定义的同时可以整体赋初值,  如果定义完之后,则只能单个的赋初值

       如何取出结构体变量中的每一个成员
       结构体变量的运算
       结构体变量和结构体变量指针作为函数参数传递的问题


       举例
       动态构造存放学生信息的结构体数组

       链表



*/