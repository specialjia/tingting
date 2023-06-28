// day22_ return和break的区别.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void f(void)
{
    int i;
    for (i = 0; i < 5; ++i)
    {
        printf("大家辛苦了!\n");
      return; // 终止被调函数, 向主调函数返回表达式的值
      //break;
    }
    printf("同志们好!\n");
 }
int main()
{
    f();

    return 0;
}

//  return 表达式的含义:
//       1. 终止被调函数, 向主调函数返回表达式的值
//       2. 如果表达式为空,则终止函数,不向被调函数返回任何值
//       3. break是用来终止循环和switch的,return是用来终止循环



//     例子:
//       void f()
//         {return; },  return用来终止函数, 不向主调函数返回表达式的值

//       int f()
//        {return 10 ;} , return用来终止函数, 向主调函数返回10