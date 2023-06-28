// day40_ 指针和数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  parr[3]与a[3]是同一个变量

#include <iostream>
void f(int* pArr, int len)
{
    int i;
   for (i = 0; i < len; ++i)
     printf("%d ", pArr[i]);         //*(pArr+i)等价与 pArr[i]  也等价于b[i]等价于*(b+i)
    printf("\n");

}

int main()
{
    int b[6] = { -1,-2,-3,4,5,-6 };
    f(b, 6);

    return 0;
}







/*
void f(int * pArr, int len)
{
    pArr[3] = 88;
}

int main()
{
    int a[6] = { 1,2,3,4,5,6 };
    printf("%d\n", a[3]);
    f(a, 6);
    printf("%d\n", a[3]);

    return 0;

}
*/




/*
void f(int * pArr, int len) //函数f可以输出任何一个一维数组的内容  (数组名, 元素个数)
{
    int i;
    for (i = 0; i < len; ++i)
        printf("%d ", *(pArr + i));//*pArr *(pArr+1)  *(pArr+2)
    printf("\n");
}

int main()   // 确定一个一维数组需要几个参数 
{
    int a[5] = { 1,2,3,4,5 };
    int b[6] = { -1,-2,-3,4,5,-6 };
    int c[100] = { 1,99,22,33 };

    f(a,5);  //  a是int *
    f(b, 6);
    f(c, 100);

    return 0;
}
*/




/*int main() //下标和指针的关系
{
    int a[5]; //a是数组名, 5是数组元素的个数, 元素是变量a[0]...a[4]
   // int a[3][4];// 3行4列, a[0][0]是第一个元素  a[i][j]是第i+行 j+1行
    int b[5];
   // a = b;//error a是常量
    printf("%#X\n", &a[0]);  // #X表示是以十六进制输出
    printf("%#X\n", a);  // 两者输出结果一样

    //  a == &a[0]


    return 0;
}*/



/* 指针和一维数组 
*    一维数组名:是个指针常量,它存放的是一维数组第一个元素的地址
*     
* 下标和指针的关系
*     如果p是个指针变量,则p[i]永远等价于*(p+i)
* 
* 确定一个一维数组需要几个参数  [如果一个函数要处理一个一维数组,则需要接收该数组的哪些信息]
*    需要两个参数:  数组第一个元素的地址;数组的长度
* 
* 
* 
* 
* 
 指针二维数组
*/