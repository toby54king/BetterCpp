// multiply.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

/*
字符串相乘（中等）
对于比较小的数字，做运算可以直接使用编程语言提供的运算符，但是如果相乘的两个因数非常大，
语言提供的数据类型可能就会溢出。一种替代方案就是，运算数以字符串的形式输入，然后模仿我们
小学学习的乘法算术过程计算出结果，并且也用字符串表示
*/

#include <iostream>
#include <vector>

using namespace std;

std::string multiply(std::string num1, std::string num2)
{
	int m = num1.size(), n = num2.size();
	std::vector<int> res(m + n, 0);
	for (int i=m-1; i>=0; i--)
	{
		for (int j=n-1; j>=0; j--)
		{
			int mul = (num1[i] - '0') * (num2[i] - '0');
			int p1 = i + j, p2 = i + j + 1;
			int sum = mul + res[p2];
			res[p2] = sum % 10;
			res[p1] = sum / 10;
		}
	}

	int i = 0;
	while (i < res.size() && res[i] == 0)
	{
		i++;
	}
	std::string str;
	for (; i<res.size();i++)
	{
		str.push_back('0' + res[i]);
	}
	return str.size() == 0 ? "0" : str;
}

int main()
{
    std::cout << "hello world!\n";
}


