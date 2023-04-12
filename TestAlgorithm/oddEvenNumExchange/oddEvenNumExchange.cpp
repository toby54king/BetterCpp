// oddEvenNumExchange.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> exchange(vector<int>& nums)
{
	int i = 0,j = nums.size()-1;
	while (i<j)
	{
		while (i<j && (nums[i] & 1) == 1) // 偶数
		{
			i++;
		}
		while (i<j && (nums[j] & 1) == 0) // 奇数
		{
			j--;
		}
		swap(nums[i], nums[j]);
	}

	return nums;
}

int main()
{
	vector<int> nums = {2,16,3,5,13,1,16,1,12,18,11,8,11,11,5,1};
	vector<int> tempNums = exchange(nums);
	for (auto n : tempNums)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;
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
