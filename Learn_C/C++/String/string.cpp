#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include <iostream>
#include <string>  //��׼��
#include <windows.h>
#include <vector>



//ÿ�����ֶ���Ҫ����������
using std::cin; 
using std::cout; using std::endl;
using std::string;
using std::vector;
int test_cin()
{
	int i = 0;
	cin >> i;
	/*cout << i;  error,û�ж�Ӧ��using����*/
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
	cin >> line;  // ÿ�ζ���һ����,ֱ���ļ���β(���з�)
	cin.ignore(); // ������з�
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
		cout << " phrase С�� slang" << endl;
	}
	else if (comparisonResult > 0)
	{
		cout << " phrase ���� slang" << endl;
	}
	else
	{
		cout << " phrase ������ slang" << endl;
	}
	return 0;
}

int test_for()   //���ڴ���s�е�ȫ���ַ�
{
	string s("Hello World!!!");
	//decltype(s.size()) punct_cnt = 0;   //ͳ��s�б����ŵ�����
	//for (auto c : s)   //����s�е�ÿ���ַ�
	//{
	//	if (ispunct(c))  // ������ַ��Ǳ�����
	//		++punct_cnt;
	//}
	//cout << punct_cnt << " punctuation characters in " << s << endl;
	//return 0;

	//ת���ɴ�д��ʽ
	for (auto& c : s)  //����s�е�ÿ���ַ� (c������)
	{
		c = toupper(c); // �ı�s���ַ���ֵ
	}
	cout << s << endl;
	return 0;
}

int test_for1()  ///ֻ�������ַ�
{
	string s("some string ");
	for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
		s[index] = toupper(s[index]);
	cout << s << endl;
	return 0;
}

int test_while()  //��0��15֮���ʮ����ת����ʮ������,ֻ���ʼ��һ���ַ���������16��ʮ����������
{

	const string hexdigits = "0123456789ABCDEF";  //���ܵ�ʮ����������
	cout << "Enter a series of the numbers between 0 and 15 " << "  separated by space. Hit ENTER when finished: " << endl;
	string result;  //���ڱ���ʮ�����Ƶ��ַ���
	string::size_type n;  //���ڱ���������
	while (cin >> n)
	{
		if (n < hexdigits.size())  //������Ч����
			result += hexdigits[n]; //�õ���Ӧ ��ʮ����������
	}
	cout << "your hex number is : " << result << endl;
	return 0;
}

int test_vector()
{
	vector<int>numbers;
	int num;
	cout << "����������(�������������������) " << endl;
	while (cin >> num)
	{
		numbers.push_back(num);
	}
	cout << "���������Ϊ: " << endl;
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
		i *= i; //��Ԫ�ص�ƽ��
	for (auto i : v)
		cout << i << " " << endl;
	return 0;
}

int test_begin()  //������
{
	string s("some string");
	//if (s.begin() != s.end())  //ȷ��s�ǿ�
	//{
	//	auto it = s.begin(); // it��ʾs��һ��Ԫ��
	//	*it = toupper(*it);
	//}
	//cout << s << endl;
	//return 0;


	// ���δ���s�ַ�ֱ������ȫ�����ַ����������հ�
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

