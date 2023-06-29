#define _CRT_SECURE_NO_WARNINGS
#include "Expressio.h"
#include <iostream>
#include <vector>
#include <string>



using std::cin;
using std::cout; using std::endl;
using std::string;
using std::vector;
using std::runtime_error;
int grade_test()
{
	const vector<string> scores = {"F","D","C","B","A","A++"};
	string lettergrade;
	int grade = 0;
	cout << "please enter your grade: "  << endl;
	cin >> grade;
	if (grade < 60)
	{
		lettergrade = scores[0];
	}
	else
	{
		lettergrade = scores[(grade - 50) / 10];  //获得字母形式的成绩
		if (grade != 100)  //只要不是A++,就考虑加加号或减号
		{
			if (grade % 10 > 7)
				lettergrade += '+';
			else if (grade % 10 < 3)
				lettergrade += '-';
				
		}

	}
	cout << lettergrade << endl;
	return 0;
}

int vowel_cnt()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	unsigned vowelTotal = 0;
	unsigned otherCnt = 0;
	cout << "please enter your  input: " << endl;
	while ( (cin >> ch))
	{
		switch (ch)
		{
		case 'a':
		case 'A':
			++aCnt;
			++vowelTotal;
			break;
		case 'e':
		case 'E':
			++eCnt;
			++vowelTotal;
			break;
		case 'i':
		case 'I':
			++iCnt;
			++vowelTotal;
			break;
		case 'o':
		case 'O':
			++oCnt;
			++vowelTotal;
			break;
		case 'u':
		case 'U':
			++uCnt;
			++vowelTotal;
			break;
		default:
			++otherCnt;
			break;
		}
		if ('0' == ch)
			break;
		 
	}


	cout << "Number of vowel a : \t" << aCnt << '\n'
		<< "Number of vowel e : \t" << eCnt << '\n'
		<< "Number of vowel i : \t" << iCnt << '\n'
		<< "Number of vowel o : \t" << oCnt << '\n'
		<< "Number of vowel u : \t" << uCnt << '\n'
		<< "Total number of vowels: \t" << vowelTotal << '\n';
	return 0;
}

int DoWhile_test()
{
	string rsp;
	do
	{
		cout << "please enter two values: ";
		int val1 = 0, val2 = 0;
		cin >> val1 >> val2;
		cout << "The sum of " << val1 << " and " << val2 << " = " << val1 + val2 << "\n\n" << "More? Enter yes or no: ";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');
	return 0;
}

int try_test()  //异常处理,从标准输入读取两个整数,输出第一个数除以第二个数的结果
{
	int num1, num2;
	cout << "Please enter your first number : " << endl;
	cin >> num1;
	cout << "Please enter next number: " << endl;
	cin >> num2;
	if (num2 != 0)
	{
		double result = static_cast<double>(num1) / num2;
		cout << result;
	}
	else
		cout << "输入错误,被除数不能为0! ";
	return 0;
}

int try_test2()
{
	int num1, num2;
	bool isValidInput = false;
	do
	{
		try
		{
			cout << "Please enter your first number : " << endl;
			cin >> num1;
			cout << "Please enter next number: " << endl;
			cin >> num2;
			if (num2 == 0)
			{
				throw runtime_error("被除数不能为0!");
			}
			double result = static_cast<double>(num1) / num2;
			cout << result;
			isValidInput = true;  // 输入有效，退出循环
		}
		catch (const std::exception& e)
		{
			std::cout << "错误提示：" << e.what() << std::endl;
			std::cout << "是否重新输入新数？(y/n): ";
			char response;
			std::cin >> response;
			if(response != 'y' && response != 'Y')
			{
				break;  // 不重新输入，退出循环
			}
		}
	} while (!isValidInput);
	return 0;
}