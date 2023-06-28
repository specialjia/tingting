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

int while1()  //while语句(求1到10之和)
{
	int sum = 0, val = 1;
	while (val <= 10)
	{
		sum += val;  //将sum+val赋值予sum
		++val;
	}
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	return 0;
}

int for1()  //for语句(1到10数字之和)
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

int while2()  //读取输入数量不定的输入数据
{
	int sum = 0;
	int value = 0;
	std::cout << "Enter the numbers:(q to quit)" << std::endl;
	//读取数据直至遇到文件结尾,计算所有读入的值的和
	while (std::cin >> value)
	{
		sum += value;
	}
	std::cout << "Sum is :" << sum << std::endl;
	return 0;
}

int if1()  //统计每个值输入了多少次
{
	int currVal = 0, val = 0;  //currVal是正在统计的数,将读取的新值存入val
	if (std::cin >> currVal)  //读取第一个数,并确保确实有数据可以处理
	{
		int cnt = 1;  //保存正在处理的当前值的个数

		while (std::cin >> val)  //读取剩余的数
		{
			if (val == currVal)  //如果值相同
				++cnt;
			else
			{
				std::cout << currVal << " occurs " << cnt << " times " << std::endl;
				currVal = val;  //记住新值
				cnt = 1;  //重置计数器
			}
		}
		std::cout << currVal << " occurs " << cnt << " times " << std::endl;
	}
	else
	{
		std::cout << "Invalid input." << std::endl;
		// 进行适当的错误处理
	}
	return 0;
}/*






*/
