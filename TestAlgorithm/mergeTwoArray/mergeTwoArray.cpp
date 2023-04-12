// mergeTwoArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 合并两个有序数组

#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeTwoArray(vector<int> & nums1, vector<int> &nums2)
{
	vector<int> mergeNums;
	int n1=0, n2 = 0,cur=0;
	while (n1<nums1.size() || n2<nums2.size())
	{
		if (n1 == nums1.size())
		{
			cur = nums2[n2++];
		}
		else if (n2 == nums2.size())
		{
			cur = nums1[n1++];
		}
		else if (nums1[n1] < nums2[n2])
		{
			cur = nums1[n1++];
		}
		else
		{
			cur = nums2[n2++];
		}
		mergeNums.emplace_back(cur);
	}
	return mergeNums;
}

int main()
{
    std::cout << "Hello World!\n";
}