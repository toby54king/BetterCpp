// nextPermutation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 下一个排列
// https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 2;
		while (i >= 0 && nums[i] >= nums[i + 1]) {
			i--;
		}
		if (i >= 0) {
			int j = nums.size() - 1;
			while (j >= 0 && nums[i] >= nums[j]) {
				j--;
			}
			swap(nums[i], nums[j]);
		}
		reverse(nums.begin() + i + 1, nums.end());
	}
};
*/

#if 1
void nextPermutation1(vector<int> &nums)
{
	if (nums.size() <= 1)
	{
		return;
	}
	
	int i = nums.size() - 1;
	while(i > 0)
	{
		if (nums[i]>nums[i-1])
		{
			break;
		}
		--i;
	}
	if (i==0)
	{
		sort(nums.begin(), nums.end());
	} 
	else
	{
		int j = nums.size() - 1;
		while (j>0)
		{
			if (nums[i] > nums[j])
			{
				break;
			}
			j--;
		}
		swap(nums[i], nums[j]);
		sort(nums.begin()+i+1, nums.end());
	}
}
#endif

void nextPermutation(vector<int>& nums) {
	if (nums.size() <= 1)return;
	int l = nums.size() - 1;
	for (; l > 0; --l)//找打准备交换的数字
	{
		if (nums[l] > nums[l - 1])break;
	}
	if (l == 0)sort(nums.begin(), nums.end());//找不到更大排序了
	else
	{
		int temp = l - 1;
		sort(nums.begin() + l, nums.end());//将其后面的数排序
		for (int i = l; i < nums.size(); ++i)//找到第一个大于nums[l]的数字用于交换。
		{
			if (nums[temp] < nums[i])
			{
				l = i;
				break;
			}
		}
		swap(nums[temp], nums[l]);
	}
	return;
}

int main()
{
	//vector<int> temp1 = {1};
	//nextPermutation1(temp1);
	vector<int> temp2 = { 1,2,3 }; // 132
	nextPermutation1(temp2);
	vector<int> temp3 = { 3,2,1 }; // 123
	nextPermutation1(temp3);
	vector<int> temp4 = { 1,1,5 }; // 151
	nextPermutation1(temp4);

    std::cout << "Hello World!\n";
}