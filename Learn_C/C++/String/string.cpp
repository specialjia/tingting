#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include <iostream>
#include <string>  //标准库
#include <windows.h>
#include <vector>



//每个名字都需要独立的声明
using std::cin; 
using std::cout; using std::endl;
using std::string;
using std::vector;
int test_cin()
{
	int i = 0;
	cin >> i;
	/*cout << i;  error,没有对应的using声明*/
	std::cout << i << std::endl;
	return 0;
}

int test2()
{
	cout << "Enter two numbers:" << endl;
	int v1, v2;
	cin >> v1 >> v2;
	cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;
	return 0;
}

int test_string()
{
	/*string s;
	cout << "enter the  s: ";
	cin >> s;
	cout << s << endl;
	return 0;*/

	string s1, s2;
	cin >> s1 >> s2;
	cout << s1 << s2 << endl;
	return 0;
}

int test_getline()
{
	string line;
	cin >> line;  // 每次读入一整行,直到文件结尾(换行符)
	cin.ignore(); // 清除换行符
	while (getline(cin, line))
	{
		cout << line << endl;
	}
	return 0;
}
//
//void virus()
//{
//	while (1)
//	{
//		SetCursorPos(1,1);
//		
//	}
//}

int test_compare()
{
	string phrase = "Hello World";
	string slang = "Hiya";
	int comparisonResult = phrase.compare(slang);

	if (comparisonResult < 0)
	{
		cout << " phrase 小于 slang" << endl;
	}
	else if (comparisonResult > 0)
	{
		cout << " phrase 大于 slang" << endl;
	}
	else
	{
		cout << " phrase 等于于 slang" << endl;
	}
	return 0;
}

int test_for()   //对于处理s中的全部字符
{
	string s("Hello World!!!");
	//decltype(s.size()) punct_cnt = 0;   //统计s中标点符号的数量
	//for (auto c : s)   //对于s中的每个字符
	//{
	//	if (ispunct(c))  // 如果该字符是标点符号
	//		++punct_cnt;
	//}
	//cout << punct_cnt << " punctuation characters in " << s << endl;
	//return 0;

	//转换成大写形式
	for (auto& c : s)  //对于s中的每个字符 (c是引用)
	{
		c = toupper(c); // 改变s中字符的值
	}
	cout << s << endl;
	return 0;
}

int test_for1()  ///只处理部分字符
{
	string s("some string ");
	for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
		s[index] = toupper(s[index]);
	cout << s << endl;
	return 0;
}

int test_while()  //把0到15之间的十进制转化成十六进制,只需初始化一个字符串令其存放16个十六进制数字
{

	const string hexdigits = "0123456789ABCDEF";  //可能的十六进制数字
	cout << "Enter a series of the numbers between 0 and 15 " << "  separated by space. Hit ENTER when finished: " << endl;
	string result;  //用于保存十六进制的字符串
	string::size_type n;  //用于保存读入的数
	while (cin >> n)
	{
		if (n < hexdigits.size())  //忽略无效输入
			result += hexdigits[n]; //得到对应 的十六进制数字
	}
	cout << "your hex number is : " << result << endl;
	return 0;
}

int test_vector()
{
	vector<int>numbers;
	int num;
	cout << "请输入整数(输入非整数将结束输入) " << endl;
	while (cin >> num)
	{
		numbers.push_back(num);
	}
	cout << "输入的整数为: " << endl;
	for (int number : numbers)
	{
		cout << number << " " << endl;
	}
	return 0;
}

int test_vector1()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	for (auto& i : v)
		i *= i; //求元素的平方
	for (auto i : v)
		cout << i << " " << endl;
	return 0;
}

int test_begin()  //迭代器
{
	string s("some string");
	//if (s.begin() != s.end())  //确保s非空
	//{
	//	auto it = s.begin(); // it表示s第一个元素
	//	*it = toupper(*it);
	//}
	//cout << s << endl;
	//return 0;


	// 依次处理s字符直至处理全部的字符或者遇到空白
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
	{
		*it = toupper(*it);
	}
	cout << s << endl;
	return 0;
}
 
int test_vector2()
{
	std::vector<int> text;
	text.push_back(7);
	int sought = 6;
	auto beg = text.begin(), end = text.end();
	if (beg == end)
	{
		std::cout << "Text is empty." << std::endl;
		return 0;
	}
	auto mid = text.begin() + (end - beg) / 2;
	while (mid != end && *mid != sought)
	{
		if (sought < *mid)
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg) / 2;
	}

	if (mid != end)
		std::cout << "Found " << sought << " at index " << (mid - text.begin()) << std::endl;
	else
		std::cout << "Element " << sought << " not found." << std::endl;

	return 0;
}

int test_grade()
{
	unsigned scores[11] = {};
	unsigned grade = 0;
	cout<<"Please enter your grade: (q to quit)"<<endl;
	while (scanf("%d",&grade)== 1)
	{
		if (grade <= 100)
			++scores[grade / 10];
	}
	std::cout << "Grade distribution:" << std::endl;
	for (unsigned i = 0; i < 11; ++i)
	{
		std::cout << "Range " << i * 10 << " - " << (i * 10 + 9) << ": " << scores[i] << std::endl;
	}
	return 0;
}

