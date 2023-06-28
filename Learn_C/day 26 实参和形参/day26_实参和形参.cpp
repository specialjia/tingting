// day 26 实参和形参.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void f(int i)
{
    printf("%d\n",i);
}
int main()
{
    f(5);

    return 0;
}

//形参和实参: 个数相同,位置一一对应,数据类型必须相互兼容 