// strIsNum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 表示数值的字符串
/*
实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：

若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <regex>

// 方法一
// 使用正则表达式
bool isNum1(std::string str)
{
	
}


// 方法二
// 常规解法 https://www.cnblogs.com/wzw0625/p/12572914.html
bool isNum2(std::string str)
{
	int flag = 0; //标记是否检测到数字
	if (s == "") return false;
	while (s[0] == ' ') s = s.substr(1); //检测字符串之前是否有空格
	if (s[0] == '+' || s[0] == '-') s = s.substr(1); //遇到正负号，向后移动
	while (((s[0] - '0') >= 0) && ((s[0] - '0') <= 9))
	{
		s = s.substr(1);
		flag = 1;
	}
	if (s[0] == '.') //若该位置为小数点，向后移，并判断是否有数字
	{
		s = s.substr(1);
		while (((s[0] - '0') >= 0) && ((s[0] - '0') <= 9))
		{
			s = s.substr(1);
			flag = 1;
		}
	}
	if (flag == 0) return false; //判断小数点之前的部分是否有数字，若没有，返回false
	flag = 0;
	if (s[0] == 'e' || s[0] == 'E') //判断是否存在e，若存在，则判断后面是否拥有数字
	{
		s = s.substr(1);
		if (s[0] == '+' || s[0] == '-') s = s.substr(1); //遇到正负号，向后移动
		while (((s[0] - '0') >= 0) && ((s[0] - '0') <= 9))
		{
			s = s.substr(1);
			flag = 1;
		}
		if (flag == 0) return false; //如果有e，但后面没有数字
	}
	while (s[0] == ' ') s = s.substr(1); //字符串末尾是空格的情况
	if (s == "") return true; //如果结束了就是true，否则返回false
	return false;
}

int main()
{
    std::cout << "Hello World!\n";
}
