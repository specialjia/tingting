#define _CRT_SECURE_NO_WARNINGS
#include "Expressio.h"
#include <iostream>
#include <vector>
#include <string>



using std::cin;
using std::cout; using std::endl;
using std::string;
using std::vector;
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

void gitTest()
{}