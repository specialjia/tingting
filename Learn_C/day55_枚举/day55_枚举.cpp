// day55_枚举.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
enum WeekDay
{
	MonDay,TuesDay,WednesDay,ThursDay, FriDay, SaturDay, SunDay

 };
void f(enum WeekDay i)
{
	switch (i)
	{
	case 0:
		printf("MonDay\n");
		break;
	case 1:
		printf("TuesDay!\n");
		break;
	case 2:
		printf("WednesDay!\n");
		break;
	case 3:
		printf("ThursDay!\n");
		break;
	case 4:
		printf("FriDay!\n");
		break;
	case 5:
		printf("SaturDay!\n");
		break;
	case 6:
		printf("SunDay!\n");
		break;
	}


}

int main()
{

	f(FriDay);


	return 0;

}


/*
//只定义了一个数据类型,并没有定义变量,该数据名字是 enum WeekDay
enum WeekDay // 枚举的意思
{
 Monday = 1,TuesDay,WednesDay,ThursDay, FriDay,SaturDay,SunDay


};

int main()
{
	// int day; 定义int类型不合适
	enum WeekDay Day = FriDay;  // 不可以写成整数 , 只能写字符串
	printf("%d\n", Day);

	return 0;
}
*/

/* 什么是枚举:
*     把一个事物所有可能的取值一一列举出来
* 
*  枚举的优点:
*    代码更安全  书写麻烦

   



*/