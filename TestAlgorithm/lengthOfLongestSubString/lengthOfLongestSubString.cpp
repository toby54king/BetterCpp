// lengthOfLongestSubString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
#if 0
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。



示例 1 :

输入: s = "abcabcbb"
	输出 : 3
	解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
	示例 2 :

	输入 : s = "bbbbb"
	输出 : 1
	解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
	示例 3 :

	输入 : s = "pwwkew"
	输出 : 3
	解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
	请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
	示例 4 :

	输入 : s = ""
	输出 : 0
#endif


#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubString(string s)
{
	unordered_map<char, int> window;
	int left = 0, right = 0;
	int res = 0;
	while (right < s.size())
	{
		char c = s[right];
		right++;
		window[c] ++;
		while (window[c]>1)
		{
			char d = s[left];
			left++;
			window[d] --;
		}
		res = std::max(res, right - left);
	}
	return res;
}

int main()
{
	string str = "abcabcbb";
	int len = lengthOfLongestSubString(str);
	std::cout << len << std::endl;
    std::cout << "Hello World!\n";
}
