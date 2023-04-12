// backtrack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 一、给定一个 没有重复 数字的序列，返回其所有可能的全排列。
// 二、有重复数字
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 没有重复 数字的序列
void backtrack(vector<vector<int>> &res, vector<int> &output, int first, int len)
{
	if (first == len)
	{
		res.emplace_back(output);
		return;
	}

	for (int i=first; i<len; ++i)
	{
		swap(output[i], output[first]);
		backtrack(res, output, first + 1, len);
		swap(output[i], output[first]);
	}
}

vector<vector<int>> permute(vector<int> &nums)
{
	vector<vector<int> > res;
	backtrack(res, nums, 0, (int)nums.size());
	return res;
}

// 有重复数字的序列
vector<bool> vis;
vector<vector<int>> permuteUnique(vector<int> &nums)
{
	vector<vector<int>> ans;
	vector<int> perm;
	vis.resize(nums.size());
	sort(nums.begin(), nums.end());
	backtrackUnique(nums, ans, 0, perm);
	return ans;
}

void backtrackUnique(vector<int> &nums,vector<vector<int>> &ans, int index, vector<int> &perm)
{
	if (index == nums.size())
	{
		ans.emplace_back(perm);
		return;
	}

	for (int i=0; i<(int)nums.size(); ++i)
	{
		if (vis[i] || (i>0 && nums[i]==nums[i-1] && !vis[i-1]))
		{
			continue;
		}
		perm.emplace_back(nums[i]);
		vis[i] = true;
		backtrackUnique(nums, ans, index, perm);
		vis[i] = false;
		perm.pop_back();
	}
}

int main()
{
    std::cout << "Hello World!\n";
}
