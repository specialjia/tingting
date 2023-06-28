// day51_何取出结构体变量中的每一个成员.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
struct Student
{
	int age;
    char sex;
	char name[100];

};

int main()
{
	struct Student st = { 20, 'F',"小娟" };
	struct Student* pst = &st;

	printf("%d %c %s\n", st.age, st.sex, st.name); 
	printf("%d %c %s\n", pst->age, pst->sex, pst->name);

	 
	return 0;
}






/*
struct Student
{
	int age;
	float score;
	char sex;


};// 分号不能省

int main()
{
	struct Student st = { 23, 88.88, 'F' }; //初始化  定义的同时赋初值
	struct Student* pst = &st;// &st吧不能改成st


	pst->age = 88; // 第二种方式  (常用)
	st.score = 10.8f;  // 第一种方式 
	printf("%d %f", st.age, pst->score);

	return 0;
}
*/




/* 如何取出结构体变量中的每一个成员:
      1. 结构体变量名.成员名
	  2. 指针变量名 -> 成员名
	      pst-> age 在计算机内部会被转化成(*pst).age  一种硬性规定
		  pst-> age 等价于 (*pst).age 也等价于 st.age
		  pst所指向的那个结构体变量中的age这个成员



*/