// testAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 暴力求解
int maxProfit(std::vector<int> &prices) {
	int n = (int)prices.size(), ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			ans = std::max(ans, prices[j] - prices[i]);
		}
	}
	return ans;
}

int maxProFit2(std::vector<int> &prices)
{
	int minprice = INT_MAX;
	int maxprice = 0;
	for (auto price:prices)
	{
		maxprice = std::max(maxprice, price - minprice);
		minprice = std::min(minprice, price);
	}
	return maxprice;
}

int main()
{
	std::vector<int> prices{ 7,1,5,3,6,4 };
	std::cout << "maxProfit:" << maxProfit(prices) << std::endl;
	std::cout << "maxProfit2:" << maxProFit2(prices) << std::endl;
	std::cout << "Hello World!\n";
}

/*
第122题：买卖股票的最佳时机 II
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。

​ 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。

示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。

​ 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。

​ 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

题目分析：首先我们看一下题目中给出的两个条件：

1、不能参与多笔交易。换句话讲，我们只能在手上没有股票的时候买入，也就是必须在再次购买前出售掉之前的股票。像我们平时买股票时的追涨杀跌是不可以的。

2、尽可能地多进行交易。这个非常好理解。像是黄金，一年基本上都有2-3次涨跌。我们只要把握住机会，在每一次涨跌的时候，低价卖入高价卖出，就可以使利益达到最大化。这个条件也是相当重要的，如果我们把这里变成，最多完成两笔交易，就变成另一道题。
*/
