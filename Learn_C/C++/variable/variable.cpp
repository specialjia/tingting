#define _CRT_SECURE_NO_WARNINGS
#include "variable.h"
#include <iostream>
#include <string>

int i = 42;
int reused()
{
	int j = 0; 
	std::cout << i << " " << j << std::endl;
	int i = 0;
	std::cout << i << "  " << j << std::endl;
	std::cout << ::i << " " << j << std::endl;
	return 0;
}

int reused1()
{
	int i = 100;
	int j = i;
	std::cout << i << " " << j << std::endl;
	return 0;
}

 
struct sales_data {
	std::string booNo;  //��ʼֵĬ��Ϊ���ַ���
	unsigned units_sold = 0;
	double revenue = 0.0;
};
