// findContinuousSequenceNum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 和为s的连续正数序列

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findContinuousSequenceNums(int sum)
{
	vector<vector<int>> res;
	for (int i=1,j=1,s=1; i<(sum+1)/2; ++i)
	{
		while (s<sum)
		{
			j++;
			s += j;
		}
		if (s == sum && j>i)
		{
			vector<int> line;
			for (int k=i; k<=j; k++)
			{
				line.emplace_back(k);
			}
			res.emplace_back(line);
		}
		s -= i;
	}
	return res;
}

int main()
{
	vector<vector<int>> res = findContinuousSequenceNums(9);
	for (size_t i = 0; i < res.size(); i++)
	{
		vector<int> tv = res[i];
		for (size_t j=0; j<tv.size(); j++)
		{
			std::cout << tv[j] << " ";
		}
		std::cout << std::endl;
	}
    std::cout << "Hello World!\n";
}
