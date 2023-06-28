// day19_函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
void max(int i, int j)   // max 是函数名称,ij是形式参数,简称形参  void表示函数没有返回值
{
    if (i > j)
    printf(" % d\n", i);
    else
        printf("%d\n", j);
}
int main()
{
    int a, b, c, d, e, f;
    a = 1, b = 2; c = 3, d = 9, e = -5, f = 100;

    max(a, b);   // 开始调用max函数
    max(c, d);
    max(e, f);


   /* if (a > b)
        printf("%d\n", a);
    else
        printf("%d\n", b);


    if(c > d)
        printf("%d\n", c);
    else
    printf("%d\n", d);


    if (e > f)
        printf("%d\n", e);
    else
        printf("%d\n", f);
   */


    return 0;

}
//函数避免了重复性操作,有利于程序的模块化
//  函数:  逻辑上:能够完成特定功能的独立的代码块
//        物理上: 能够接受数据; (也可以不接收数据)
//               能够你对接受的数据进行处理; 
//               能够将数据处理的结果返回 (也可以不返回任何值)

//  总结:函数是个工具,它是为了解决大量类似问题而设计的
//      函数可以当作是黑匣子