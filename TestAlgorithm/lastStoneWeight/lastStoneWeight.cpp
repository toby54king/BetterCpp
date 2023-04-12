﻿// lastStoneWeight.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/last-stone-weight-ii/solution/1049-cshuang-bai-de-dong-tai-gui-hua-by-0qra7/
#if 0
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y - x。
最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。

示例：

输入：[2, 7, 4, 1, 8, 1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为[2, 7, 1, 8, 1]，
组合 7 和 8，得到 1，所以数组转化为[2, 1, 1, 1]，
组合 2 和 1，得到 1，所以数组转化为[1, 1, 1]，
组合 1 和 1，得到 0，所以数组转化为[1]，这就是最优值。
#endif

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int lastStoneWeight(vector<int> &stones)
{
	int n = stones.size();
	int sum = accumulate(stones.begin(), stones.end(), 0);
	int target = sum / 2;
	vector<int> dp(target+1, 0);
	for (int i=0; i<n; i++)
	{
		for (int x=target; x>-1; x--)
		{
			if (stones[i]<=x)
			{
				dp[x] = std::max(dp[x], dp[x-stones[i]]+stones[i]);
			}
			else
			{
				break;
			}
		}
	}
	return (sum-dp[target]-dp[target]);
}

int main()
{
	vector<int> stones = { 2, 7, 4, 1, 8, 1 };
	int ret = lastStoneWeight(stones);
	std::cout << ret << std::endl;
    std::cout << "Hello World!\n";
}
