// removeRepeatedNum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// 找出一组数中任意重复的数字{2,3,1,0,2,5,3}
// 暴力解法
bool removeRepeatedNum(const std::vector<int> &nums, int &findNum)
{
	if (nums.empty()) return false;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[i] == nums[j])
			{
				findNum = nums[i];
				return true;
			}
		}
	}
	return false;
}

bool removeRepeatedNum2(std::vector<int> nums, int &findNum)
{
	if (nums.empty()) return false;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == nums[nums[i]] && nums[i] != i)
		{
			findNum = nums[i];
			return true;
		}
		else
		{
			std::swap(nums[i], nums[nums[i]]);
		}
	}
	return false;
}

int findRepeatNumber(std::vector<int>& nums)
{
	unordered_map <int, int> m;
	for (int num : nums)
	{
		if (++m[num] > 1)
			return num;
	}
	return -1;
}

int findRepeatNumber4(vector<int>& nums) 
{
	//if (nums.empty()) return -1;
	//int i = 0;
	for (int i = 0; i < nums.size(); )
	{
		std::cout << " i: " << i << std::endl;
		if (nums[i] == i)
		{
			std::cout << "findRepeatNumber4 i: " << i << std::endl;
			i++;
			continue;
		}
		if (nums[i] == nums[nums[i]])
		{
			return nums[i];
		}
		std::swap(nums[i], nums[nums[i]]);
	}
	return -1;
}

int findRepeatNumber5(vector<int>& nums) {
	int i = 0;
	while (i < nums.size()) {
		if (nums[i] == i) {
			i++;
			continue;
		}
		if (nums[nums[i]] == nums[i])
			return nums[i];
		swap(nums[i], nums[nums[i]]);
	}
	return -1;
}

int main()
{
	std::vector<int> nums = { 3, 4, 2, 0, 0, 1 };
	int findNum = 0;
	bool isFind = false;
	//isFind = removeRepeatedNum(nums, findNum);
#if 0
	isFind = removeRepeatedNum2(nums, findNum);
	findNum = findRepeatNumber(nums);
	if (isFind)
	{
		std::cout << "find num: " << findNum << std::endl;
	}
	else
	{
		std::cout << "not find it!" << std::endl;
	}
#endif
	int num = findRepeatNumber4(nums);
	std::cout << "num: " << num << std::endl;

	std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
