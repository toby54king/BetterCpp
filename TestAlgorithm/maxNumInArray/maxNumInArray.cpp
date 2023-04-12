// maxNumInArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 最大子序和

#include <iostream>
#include <vector>
using namespace std;

int maxNumInArray(const vector<int> &nums)
{
	if (nums.empty()) return 0;

	int pre = 0;
	int maxSum = nums[0];
	for (const auto &num : nums)
	{
		pre = (pre+num) > num ? (pre+num) : num;
		maxSum = maxSum > pre ? maxSum : pre;
	}
	return maxSum;
}


int main()
{
    std::cout << "Hello World!\n";
}