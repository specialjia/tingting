// day36_指针的常见的问题2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int i = 5;
    int* p;
    int* q;
    p = &i;
   // *q = p; //  error  *q为int型  p为int*两者不可转换
   //*q = *p;  //error   
    p = q;  // error    q是垃圾值,q赋给p,p也变成垃圾值

    printf("%d\n", *q);  /*q的空间是属于本程序的, 所以可以读写q的内容, 但是如果q内部是垃圾值, 则本程序不能读写* q的内容
                          因为*q所代表内存单元的控制权限并没有分配给本程序*/
    return 0;
}


// 