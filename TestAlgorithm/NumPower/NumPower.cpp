// NumPower.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 数值的整数次幂

#include <iostream>

using namespace std;

// 方法一
double power(double base, int exponent)
{
	double result = 1.0;
	for (int i=1; i<exponent; ++i)
	{
		result *= base;
	}
	return result;
}

// 方法二
bool g_invalidInput = false; // 标志数值结果是否有效
double power(double base, int expontent)
{
	g_invalidInput = false;
	if (equalNum(base, 0.0) && expontent<0) // 0或者小于0，无效的数值
	{
		g_invalidInput = true;
		return 0;
	}

	unsigned int absExpontent = (unsigned int)(expontent);
	if (expontent < 0)
	{
		absExpontent = (unsigned int)(expontent);
	}

	double result = powerWithUnsignedExpontent(base, absExpontent);
	if (expontent<0)
	{
		result = 1.0 / result;
	}
	return result;
}

double powerWithUnsignedExpontent(double base, unsigned int expontent)
{
	double result = 1.0;
	for (int i=1; i<=expontent; ++i)
	{
		result *= base;
	}
	return result;
}

bool equalNum(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2) < 0.0000001)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 方法三
double powerWithUnsignedExpontent(double base, unsigned int expontent)
{
	if (expontent == 0)
	{
		return 1;
	}
	if (expontent == 1)
	{
		return base;
	}

	double result = powerWithUnsignedExpontent(base, expontent);
	result *= result;
	if (expontent & 0x1 == 1)
	{
		result *= base;
	}
	return result;
}
int main()
{
    std::cout << "Hello World!\n";
}
