// isHuiWenNum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 判断一个字符串是不是回文字符串，只考虑字母和数字，不考虑大小写
// https://leetcode-cn.com/problems/valid-palindrome/solution/yan-zheng-hui-wen-chuan-by-leetcode-solution/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 方法一
bool isHuiWen1(string str)
{
	string tStr;
	for (auto ch : str)
	{
		if (isalnum(ch))
		{
			tStr += tolower(ch);
		}
	}
	string tStr(tStr.rbegin(), tStr.rend());
	return str == tStr;
}

bool isHuiWen2(string str)
{
	string tStr;
	for (auto ch : str)
	{
		if (isalnum(ch))
		{
			tStr += tolower(ch);
		}
	}
	int left = 0;
	int right = tStr.size();
	while (left<right)
	{
		if (tStr[left] != tStr[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}

bool isHuiWen3(string str)
{
	int left = 0;
	int right = str.size();
	while (left<right)
	{
		while (left<right && isalnum(str[left]))
		{
			left++;
		}
		while (left<right && isalnum(str[right]))
		{
			right++;
		}
		if (left<right)
		{
			if (tolower(str[left]) != tolower(str[right]))
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
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
