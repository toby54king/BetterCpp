// mostCommonWord.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/most-common-word/solution/cha-xi-biao-liang-chong-jie-fa-by-zhu-qu-0gne/
#if 0
给定一个段落(paragraph) 和一个禁用单词列表(banned)。返回出现次数最多，同时不在禁用列表中的单词。

题目保证至少有一个词不在禁用列表中，而且答案唯一。

禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。



示例：

输入 :
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
输出 : "ball"
	解释 :
	"hit" 出现了3次，但它是一个禁用的单词。
	"ball" 出现了2次(同时没有其他单词出现2次)，所以它是段落里出现次数最多的，且不在禁用列表中的单词。
	注意，所有这些单词在段落里不区分大小写，标点符号需要忽略（即使是紧挨着单词也忽略， 比如 "ball,"），
	"hit"不是最终的答案，虽然它出现次数更多，但它在禁用单词列表中。
#endif 

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

string mostCommonWorld(string paragraph, vector<string>& banned)
{
	unordered_map<string, int> cnt;
	unordered_set<string> ban;
	for (auto &w : banned)
	{
		ban.emplace(w);
	}

	int maxcnt = 0;
	string ans;

	for (auto &c : paragraph)
	{
		c = isalpha(c) ? c : ' ';
	}

	stringstream ss(paragraph);
	string temp;
	while (ss >> temp)
	{
		std::cout << temp << std::endl;
		for (auto &c : temp)
		{
			c = tolower(c);
		}
		if (ban.count(temp) != 0)
		{
			continue;
		}
		cnt[temp]++;
		if (cnt[temp] > maxcnt)
		{
			maxcnt = cnt[temp];
			ans = temp;
		}
	}
	return ans;
}


int main()
{
	string s = "Bob hit a ball, the hit BALL flew far after it was hit.";
	std::vector<string> banned = {"hit"};
	string temp = mostCommonWorld(s, banned);
	std::cout << temp << std::endl;
    std::cout << "Hello World!\n";
}
