#define _CRT_SECURE_NO_WARNINGS
#include "function.h"
#include <iostream>
#include <string>



using std::cout;
using std::cin;
using std::endl;
using std::string;


int fact(int val);
int factorial();  // ����ԭ��
int factorial()  //����һ�����Ľ׳�
{
	int a = 1;
	cout << "please enter the number:";
	cin >> a;
	int j = fact(a);  //����fact����
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

bool isShorter(const string& s1, const string& s2)  //�Ƚ�����string����ĳ���
{
	return s1.size() <= s2.size();
}
int ComLen_test()
{
	string s1 = "Hello";
	string s2 = "World";
	if (isShorter(s1, s2))
		cout << "s1�ĳ���С�ڵ���s2";
	else
		cout << "s1�ĳ��ȴ���s2";
	return 0;
}

//��ζ��庯�����ܷ��ص�һ�γ���ʱ��λ��Ҳ���س��ֵĴ���
//����s��c��һ�γ��ֵ�λ������,  �����β�occursͳ��c���ֵ��ܴ���
string::size_type find_char(const string s, char c, string::size_type& occurs)
{
	auto ret = s.size();  //��һ�γ��ֵ�λ��(����еĻ�)
	occurs = 0;  // ���ñ�ʾ���ִ������β�ֵ
	for (decltype(ret) i = 0; i != s.size(); ++i)
	{
		if (s[i] == c)
		{
			if (ret == s.size())
				ret = i;
			++occurs;
		}
	}
	return ret;   // c���ִ���ͨ��occurs��ʽ�ط���
}