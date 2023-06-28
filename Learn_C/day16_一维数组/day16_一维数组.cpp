﻿// day16_一维数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 为n个变量连续分配存储空间;  所有的变量数据类型必须相同;   所有变量所占的字节大小必须相等;

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int a[5];   //这5个数组一定是连续分配的
    int i;

    scanf("%d", &a[0]);
    printf("a[0]= %d\n", a[0]);

    scanf("%d", &a[3]);
    printf("a[3]= %d\n", a[3]);


    for (i = 0; i < 5; ++i)  //a[0]到a[5]全部输出
        printf("%d\n", a[i]);

    return 0;
}



// 一维数组的操作:
//   初始化: 完全初始化 int a[5] = { 1,2,3,4,5 };
//          不完全初始化,未被初始化的元素自动为零   int a[5] = { 1,2,3 };
//          不初始化,所有元素都是垃圾值  int a[5];
//           清零    int a[5] = {0}
// 
//     错误写法: 1.  int a[5]; a[5]={ 1,2,3,4,5 }; 错误,只有在定义数组的同时才可以整体赋值,其他情况下整体赋值都是错误的
// 
//              2.  int a[5] = { 1,2,3,4,5 };  a[5] = 100 错误 因为没有a[5]这个元素,最大是a[4]
// 
//              3.  int a[5] = { 1,2,3,4,5 }; int b[5]如果要把a数组中的值全部赋值给b数组
//                  错误写法: b = a;
//                  正确写法: for(i = 0; i<5; ++i)
//                             b[i] = a[i];
// 
//   赋值 ,  排序,  求最大/小值,   倒置,   查找,  插入,  删除
