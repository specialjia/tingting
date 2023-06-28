// day13_break用于多个for循环.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int i, j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 1; j < 4; ++j)
            break;  // 在多层循环中, break只能终止离他最近的一个for循环
        printf("同志们好!\n");
    }

    return 0;
}
//在多层switch嵌套中,break只能终止离他最近的一个switch
/*
{int x= 1, y=0, a=0, b=0;
 switch(x)   // 第一个switch
 {
   case 1:
   switch(y) //第二个switch
   {
   case 0:
     a++;
     break;  //终止的是第二个switch
   case 1:
     b++;
     break;
   }
   b = 100;
   break;

   case 2:
   a++;
   b++;
   break;
 }
 printf("%d %d\n",a,b);  //最终输出结果为1 100

 return 0;
}
*/