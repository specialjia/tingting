// day37_指针经典程序-互换两个数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 要自己敲出来

#include <iostream>
void huhuan3(int* p, int* q)// 形参名字是p和q,接收实参数据的是p和q
{
	int t;   // 如果要互换p和q的值, 则t必须是int,不能是int*,否则语法n会出错  

	t = *p;  //p是int*, *p是int型
	*p = *q;
	*q = t;

}

int main()
{
	int a = 3;
	int b = 5;
	huhuan3(&a, &b);  //huhuan2(a, b)是错误的;  huhuan2(*p, *q)也是错误的
	printf("a = %d, b = %d", a, b);


	return 0;
}






//  不能完成互换
/*void huhuan2(int* p, int* q)
{
	int* t;// 如果要互换p和q的值, 则t必须是int*,不能是int,否则会出错

	t = p;
	p = q;
	q = t;

}

int main()
{
	int a = 3;
	int b = 5;
	huhuan2(&a, &b);  //huhuan2(a, b)是错误的;  huhuan2(*p, *q)也是错误的
	printf("a = %d, b = %d", a, b);


	return 0;
}
*/





//   不能完成互换
/*void huhuan1(int a, int b)
{
	int t;
	t = a;
	a = b;
	b = t;
	return;


 }


int main()
{
	int a = 3;
	int b = 5;
	
	huhuan1(a,b);

	printf("a = %d, b = %d\n", a , b);

	return 0;
}
*/
 
// 