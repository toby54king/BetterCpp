// validPalindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/valid-palindrome-ii/solution/yan-zheng-hui-wen-zi-fu-chuan-ii-by-leetcode-solut/

#if 0

给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
	输出 : True
	示例 2 :

	输入 : "abca"
	输出 : True
	解释 : 你可以删除c字符。
#endif

#include <iostream>
#include <string>
using namespace std;

bool checkPalinDrom(const string &s, int low, int high)
{
	for (int i=low, j=high; i<j; ++i,--j)
	{
		if (s[i] != s[j])
		{
			return false;
		}
	}
	return true;
}
bool validPalinDrom(string s)
{
	int low = 0, high = s.size() - 1;
	while (low<high)
	{
		char c1 = s[low], c2 = s[high];
		if (c1 == c2)
		{
			++low;
			--high;
		}
		else
		{
			return checkPalinDrom(s, low, high - 1) || checkPalinDrom(s, low + 1, high);
		}
	}
	return true;
}

int main()
{
	std::string s = "abca";
	bool valid = validPalinDrom(s);
	if (valid)
	{
		std::cout << "is valid palin drom!" << std::endl;
	}
	else
	{
		std::cout << "is invalid palin drom!" << std::endl;
	}
    std::cout << "Hello World!\n";
}
