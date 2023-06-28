// day49_结构体.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

 //第三种方式
struct 
{
    int age;
    float score;
    char sex;

}st3;

int main()
{
    struct Student3 st = { 80, 66.6, 'F' };

    return 0;
}



/*
// 第二种方式
struct Student2
{
    int age;
    float score;
    char sex;

}st2;

int main()
{
    struct Student2 st = { 80, 66.6, 'F' };

    return 0;
}

*/



//第一种方式
/*
struct Student
{
    int age;
    float score;
    char sex;

};
*/








/* 为什么需要结构体:
*     为了表达一些复杂的事务, 而普通的基本类型无法满足实际要求
* 
* 什么是结构体:
*      把一些基本类型数据组合在一起形成的一个新的复合数据类型
* 
*  如何定义结构体:  3种方式  推荐使用第一种
*      
*  
* 
* 
* 
* 
* 
* 
*/