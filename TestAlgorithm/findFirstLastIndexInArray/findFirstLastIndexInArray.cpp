// findFirstLastIndexInArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/zai-pai-xu-shu-zu-zhong-cha-zhao-yuan-su-de-di-3-4/
// 在排序数组中查找元素的第一个和最后一个位置 二分

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
	if (nums.empty())
	{
		return vector<int>{-1, -1};
	}

	int l = 0, r = (int)nums.size() - 1;
	while (l<r)
	{
		int mid = (l + r ) >> 1;
		if (nums[mid]<target)
		{
			l = mid + 1;
		}
		else if (nums[mid] == target)
		{
			r = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	int ret1 = l;
	if (nums[l] != target)
	{
		return vector<int>{-1,-1};
	}
	l = 0, r = (int)nums.size() - 1;
	while (l<r)
	{
		int mid = (l + r + 1) >> 1; // 右取整
		if (nums[mid]<target)
		{
			l = mid;
		}
		else if (nums[mid] == target)
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	return vector<int>{ret1, r};
}

int main()
{
	vector<int> nums = {5,7,7,8,8,10};
	vector<int> tv = searchRange(nums,8);
	std::cout << tv[0] << " " << tv[1] << "\n";
    std::cout << "Hello World!\n";
}
