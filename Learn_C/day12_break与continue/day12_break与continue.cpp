// day12_break与continue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int i;
   /* switch (2)
    {
    case 2:
        printf("哈哈!\n");
        break;     //ok的,break可以用于switch
    }
    */
    for (i = 0; i < 3; ++i)
    {
        if (3 > 2)
            break;          //break虽然是if内部中的语句,但是break终止的是外部外部的for循环
        printf("嘿嘿!\n");  //永远不会输出
    }

        return 0;
}

// break如果用于循环是用来终止循环的;
// break如果用于switch,则是用来终止switch;
// break不能直接用于if,除非if属于循环内部的一个子句;