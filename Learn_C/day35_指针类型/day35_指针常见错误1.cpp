// day35_指针类型.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{  
    int* p;
    int i = 5;
    *p = i;  //不可以写*p
    printf("%d\n," * p);

    return 0;
}

// 