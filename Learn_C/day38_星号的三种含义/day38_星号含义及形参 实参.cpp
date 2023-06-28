// day38_星号的三种含义.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
// 检测实参与形参是否是同一个变量  实参与形参永远是不同的变量

void f(int i)
{
	i = 99;

}

int main(void)  
{
	int i = 6;
	printf("i = %d\n", i);
	f(i);
	printf("i = %d\n", i);


	return 0;
}








/*int main()
{
	int * p;

	int i = 5;
	char ch = 'A';
	p = &i;     //p = ch;  p = 5;  error
	*p = 99;
	printf("i= %d, *p= %d\n", i, *p);

	                 
	return 0;
}
*/


/*  星号的三种含义 

     1)乘法
     2)定义指针变量  int * p;
	 3)指针运算符,该运算符放在已经定义好的指针变量的前面.   
	 如果p是已经定义好的指针变量,*p表示以p的内容为地址的变量
*/