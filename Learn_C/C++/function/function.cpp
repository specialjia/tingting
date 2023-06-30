#define _CRT_SECURE_NO_WARNINGS
#include "function.h"
#include <iostream>
#include <string>



using std::cout;
using std::cin;
using std::endl;
using std::string;


int fact(int val);
int factorial();  // 函数原型
int factorial()  //计算一个数的阶乘
{
	int a = 1;
	cout << "please enter the number:";
	cin >> a;
	int j = fact(a);  //调用fact函数
	cout << a<<"!  is " << j << endl;
	return 0;
}
int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}

bool isShorter(const string& s1, const string& s2)  //比较两个string对象的长度
{
	return s1.size() <= s2.size();
}
int ComLen_test()
{
	string s1 = "Hello";
	string s2 = "World";
	if (isShorter(s1, s2))
		cout << "s1的长度小于等于s2";
	else
		cout << "s1的长度大于s2";
	return 0;
}

//如何定义函数既能返回第一次出现时的位置也返回出现的次数
//返回s中c第一次出现的位置索引,  引用形参occurs统计c出现的总次数
string::size_type find_char(const string s, char c, string::size_type& occurs)
{
	auto ret = s.size();  //第一次出现的位置(如果有的话)
	occurs = 0;  // 设置表示出现次数的形参值
	for (decltype(ret) i = 0; i != s.size(); ++i)
	{
		if (s[i] == c)
		{
			if (ret == s.size())
				ret = i;
			++occurs;
		}
	}
	return ret;   // c出现次数通过occurs隐式地返回
}