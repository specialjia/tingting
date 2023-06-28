// day42_一个指针变量所占的字节.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
	char ch = 'A';
	int i = 99;
	double x = 66.6;
	char* p = &ch;
	int* q = &i;
	double* r = &x;
	printf("%d %d %d\n", sizeof(p), sizeof(q), sizeof(r));

	return 0;
}

/*  一个指针变量到底占几个字节  
*      sizeof(数据类型)  or sizeof(变量名),    该返回值就是该数据所占的字节
*      例子:sizeof(int) = 4
*      假设p指向char类型变量  (一个字节)
*      假设q指向int类型变量    (四个字节)
*      假设r指向double类型变量  (八个字节)
*     p  q r本身所占的字节是一样的
* 总结: 一个指针变量,无论它指向的变量占几个字节,该指针本身只占四个字节
*      一个变量的地址是使用该变量首字节的地址来表示的 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* */