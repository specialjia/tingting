#include "IO.h"
#include <iostream>


int cout1()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
	return 0;

}

int while1()  //while���(��1��10֮��)
{
	int sum = 0, val = 1;
	while (val <= 10)
	{
		sum += val;  //��sum+val��ֵ��sum
		++val;
	}
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	return 0;
}

int for1()  //for���(1��10����֮��)
{
	int sum = 0;
	int val = 1;
	for (val = 1; val <= 10; ++val)
	{
		sum += val;
	}
	std::cout << "sum of 1 to 10 inclusive is " << sum << std::endl;
	return 0;
}

int while2()  //��ȡ����������������������
{
	int sum = 0;
	int value = 0;
	std::cout << "Enter the numbers:(q to quit)" << std::endl;
	//��ȡ����ֱ�������ļ���β,�������ж����ֵ�ĺ�
	while (std::cin >> value)
	{
		sum += value;
	}
	std::cout << "Sum is :" << sum << std::endl;
	return 0;
}

int if1()  //ͳ��ÿ��ֵ�����˶��ٴ�
{
	int currVal = 0, val = 0;  //currVal������ͳ�Ƶ���,����ȡ����ֵ����val
	if (std::cin >> currVal)  //��ȡ��һ����,��ȷ��ȷʵ�����ݿ��Դ���
	{
		int cnt = 1;  //�������ڴ���ĵ�ǰֵ�ĸ���

		while (std::cin >> val)  //��ȡʣ�����
		{
			if (val == currVal)  //���ֵ��ͬ
				++cnt;
			else
			{
				std::cout << currVal << " occurs " << cnt << " times " << std::endl;
				currVal = val;  //��ס��ֵ
				cnt = 1;  //���ü�����
			}
		}
		std::cout << currVal << " occurs " << cnt << " times " << std::endl;
	}
	else
	{
		std::cout << "Invalid input." << std::endl;
		// �����ʵ��Ĵ�����
	}
	return 0;
}/*






*/
