// productExceptSelf.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/product-of-array-except-self/
// 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//示例 :
//
//输入: [1, 2, 3, 4]
//	输出 : [24, 12, 8, 6]

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExecptSelf(vector<int> &nums)
{
	if (nums.empty())
	{
		return {};
	}

	int length = nums.size();
	vector<int> l(length,0), r(length,0), res(length,0); // 不初始化为0，结果报错

	l[0] = 1; // l[i]为索引左侧所有元素的乘积，因为索引0的左侧没有元素，所以此处赋值为1
	for (int i=1; i<length; ++i)
	{
		l[i] = nums[i - 1] * l[i - 1];
	}

	r[length - 1] = 1;// l[i]为索引右侧所有元素的乘积，因为索引length-1的右侧没有元素，所以此处赋值为1
	for (int i=length-2; i>=0; i--)
	{
		r[i] = nums[i + 1] * r[i + 1];
	}

	for (int i=0; i<length; i++)
	{
		res[i] = l[i] * r[i];
	}
	return res;
}

int main()
{
	vector<int> nums = { 1, 2, 3, 4 };
	vector<int> res = productExecptSelf(nums);
	for (auto n : res)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;
    std::cout << "Hello World!\n";
}
