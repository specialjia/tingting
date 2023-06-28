// day52_体变量和结构体变量指针作为函数参数传递的问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

struct Student
{
	int age;
	char sex;
	char name[100];

};


void InputStudent(struct Student *pstu);  // 函数前置声明
void OutputStudent(struct Student *pss);

int main()
{
	struct Student st = {0};

	InputStudent(&st);// 对结构体变量输入  必须发送st的地址
	//printf("%d %c %s\n", st.age, st.sex, st.name);

	printf("%d\n", sizeof(st));

	OutputStudent(&st);// 对结构体变量输出  可以发送st的地址也可以直接发送st的内容  但是为了减少内存的耗费,也为了提高执行速度,推荐发送地址


	return  0;
}

void OutputStudent(struct Student *pss)
{
	printf("%d %c %s\n", pss->age, pss->sex, pss->name);

}

void InputStudent(struct Student* pstu) // pstu只占了四个字节
{
	(*pstu).age = 10;
	strcpy(pstu->name, "张三");
	pstu->sex = 'F';

}




/*  本函数无法修改主函数22行st的值,所以本函数是错误的 
void InputStudent(struct Student stu)
{
	stu.age = 10;
	strcpy(stu.name, "张三");  //字符串的使用,  不能写成stu.name = "张三"
	stu.sex = 'F';

}
*/





/*  结构体变量和结构体变量指针作为函数参数传递的问题
*      推荐使用结构体指针变量作为函数参数来传递
* 
  示例:
    发送地址还是内容
  目的:指针的有点之一:
        快速的传递数据
		耗用内存小
		执行速度快


结构体变量的运算:
    结构体变量不能相加 不能相减 也不能相互乘除
    但是结构体变量可以相互赋值  st1 = st2


*/  