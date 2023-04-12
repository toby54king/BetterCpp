﻿// slideWindow.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// // https://leetcode-cn.com/problems/minimum-window-substring/solution/zui-xiao-fu-gai-zi-chuan-by-leetcode-solution/
// 最小覆盖子串

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t)
{
	unordered_map<char, int> need, window;
	for (char c : t)
	{
		need[c]++;
	}
	int left = 0, right = 0;
	int valid = 0;
	int start = 0, len = INT_MAX;
	while (right < s.size())
	{
		char c = s[right];
		right++;
		if (need.count(c))
		{
			window[c]++;
			if (window[c] == need[c])
			{
				valid++;
			}
			
		}
		while (valid == need.size())
		{
			if (right - left < len)
			{
				start = left;
				len = right - left;
			}
			char d = s[left];
			left++;
			if (need.count(d))
			{
				if (window[d] == need[d])
				{
					valid--;
				}
				window[d]--;
			}
		}
	}
	return len == INT_MAX ? "" : s.substr(start, len);
}


int main()
{
	string s = "ADOBECODEBANC", t = "ABC";
	string temp = minWindow(s, t);
	std::cout << temp << std::endl;
}

