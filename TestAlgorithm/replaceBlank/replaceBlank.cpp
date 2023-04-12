// replaceBlank.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 替换字符串中的空格

#include <iostream>
using namespace std;

// length为字符数组string的总长度
void replaceBlank(char string[], int length)
{
	if (string == nullptr && length <= 0)
	{
		return;
	}

	int oriLen = 0;
	int numOfBlank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++oriLen;
		if (string[i] == ' ')
		{
			++numOfBlank;
		}
		++i;
	}

	int newLength = oriLen + numOfBlank * 2;
	if (newLength > length)
	{
		return;
	}

	int indexOfOri = oriLen;
	int indexOfNew = newLength;
	while (indexOfOri >= 0 && indexOfNew>indexOfOri)
	{
		if (string[indexOfOri] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOri];
		}
		--indexOfOri;
	}
}

int main()
{
    std::cout << "Hello World!\n";
}
