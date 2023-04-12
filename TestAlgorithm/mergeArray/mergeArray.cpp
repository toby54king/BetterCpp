// mergeArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/merge-intervals/solution/he-bing-qu-jian-by-leetcode-solution/
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，
// 并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
#if 0
示例 1：

输入：intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
输出：[[1, 6], [8, 10], [15, 18]]
解释：区间[1, 3] 和[2, 6] 重叠, 将它们合并为[1, 6].
示例 2：

输入：intervals = [[1, 4], [4, 5]]
输出：[[1, 5]]
解释：区间[1, 4] 和[4, 5] 可被视为重叠区间。
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeArray(vector<vector<int>> &intervals)
{
	if (intervals.empty())
	{
		return {};
	}
	std::sort(intervals.begin(), intervals.end());

	vector<vector<int>> merge;
	for (size_t i = 0; i < intervals.size(); i++)
	{
		int l = intervals[i][0], r = intervals[i][1];
		if (merge.empty() || merge.back()[1] < l)
		{
			merge.emplace_back(intervals[i]);
		} 
		else
		{
			merge.back()[1] = std::max(merge.back()[1], r);
		}
	}
	return merge;
}

int main()
{
	std::vector<vector<int>> intervals = { {1,4},{4,5} };
	vector<vector<int>> merge = mergeArray(intervals);
	for (auto f : merge)
	{
		for (auto s : f)
		{
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
    std::cout << "Hello World!\n";
}
