// day11_switch循环.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 电梯程序举例

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int val = 0;
    printf("请输入您要进入的楼层: ");
    scanf("%d", &val);

    switch (val)
    {
    case 1:              // 程序的入口
        printf("1层开!\n");
        break;

    case 2:
        printf("2层开!\n");
        break;

    case 3:
        printf("3层开!\n");
        break;
    default:   // 默认的意思,程序的入口
        printf("还没有你盖到这一层!\n" );
        break;

    }

 return 0;
}
