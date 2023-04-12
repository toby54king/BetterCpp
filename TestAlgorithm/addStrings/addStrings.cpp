// addStrings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/add-strings/solution/zi-fu-chuan-xiang-jia-by-leetcode-solution/
#if 0
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
提示：
num1 和num2 的长度都小于 5100
num1 和num2 都只包含数字 0 - 9
num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
#endif

#include <iostream>
#include <vector>

using namespace std;

string addString(string num1, string num2)
{
	int i = num1.length() - 1, j = num2.length() - 1, add = 0;
	string ans = "";
	while (i>=0 || j>=0 || add != 0)
	{
		int x = i >= 0 ? num1[i] - '0' : 0;
		int y = j >= 0 ? num2[j] - '0' : 0;
		int res = x + y + add;
		ans.push_back('0' + res % 10);
		add = res / 10;
		i--;
		j--;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	string num1 = "86043", num2 = "5582";
	string str = addString(num1, num2);
	std::cout << str.c_str() << std::endl;
    std::cout << "Hello World!\n";
}
