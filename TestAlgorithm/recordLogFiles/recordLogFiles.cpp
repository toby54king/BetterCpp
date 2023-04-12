// recordLogFiles.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/reorder-data-in-log-files/solution/c-stable_sort-by-you-yuan-de-cang-qiong-ujob/
#if 0
给你一个日志数组 logs。每条日志都是以空格分隔的字串，其第一个字为字母与数字混合的 标识符 。

有两种不同类型的日志：

字母日志：除标识符之外，所有字均由小写字母组成
数字日志：除标识符之外，所有字均由数字组成
请按下述规则将日志重新排序：

所有 字母日志 都排在 数字日志 之前。
字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。
数字日志 应该保留原来的相对顺序。
返回日志的最终顺序。



示例 1：

输入：logs = ["dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"]
输出：["let1 art can", "let3 art zero", "let2 own kit dig", "dig1 8 1 5 1", "dig2 3 6"]
解释：
字母日志的内容都不同，所以顺序为 "art can", "art zero", "own kit dig" 。
数字日志保留原来的相对顺序 "dig1 8 1 5 1", "dig2 3 6" 。
示例 2：

输入：logs = ["a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"]
输出：["g1 act car", "a8 act zoo", "ab1 off key dog", "a1 9 2 3 1", "zo4 4 7"]
#endif

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> reorderLogFiles(vector<string> &logs)
{
	auto func = [](const string &str)->string
	{
		auto pos = str.find(' ');
		if (isalpha(str.at(pos+1)))
		{
			return "0" + str.substr(pos) + str.substr(0, pos);
		}
		return "1";
	};

	auto cmp = [=](const string str1, const string str2)
	{
		return func(str1) < func(str2);
	};
	stable_sort(logs.begin(), logs.end(), cmp);
	return logs;
}

int main()
{
	vector<string> logs = { "a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo" };
	reorderLogFiles(logs);
	for (size_t i = 0; i < logs.size(); i++)
	{
		std::cout << logs[i] << std::endl;
	}
    std::cout << "Hello World!\n";
}
