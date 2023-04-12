// numberOf1InBinary.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 二进制中1的个数

#include <iostream>

int numberOf1(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)
		{
			count++;
		}
		n = n >> 1;
	}
	return count;
}

int numberOf2(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
		{
			count++;
		}
		flag = flag << 1;
	}
	return count;
}

int numberOf3(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1) & n;
	}
	return count;
}

int main()
{
    std::cout << "Hello World!\n";
}