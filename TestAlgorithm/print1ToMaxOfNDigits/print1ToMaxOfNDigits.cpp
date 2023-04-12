// print1ToMaxOfNDigits.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 打印1到最大的n位数

#include <iostream>

using namespace std;

// 方法一
void print1ToMaxOfNDigits(int n)
{
	int number = 1;
	int i = 0;
	while (i++ < n)
	{
		number *= 10;
	}
	for (i =1; i<number; ++i)
	{
		std::cout << i;
	}
}

// 方法二
#if 0
void print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
	{
		return;
	}
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\n';
	while (!increment(number))
	{
		printNumber(number);
	}
	delete []number;
}

bool increment(char *number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i=nLength - 1; i>=0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength -1)
		{
			nSum++;
		}

		if (nSum >= 10)
		{
			if (i== 0)
			{
				isOverflow = true;
			} 
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}
#endif

void printNumber(char *number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (size_t i = 0; i < nLength; i++)
	{
		if (isBeginning0 && number[i] != '0')
		{
			isBeginning0 = false;
		}
		if (!isBeginning0)
		{
			std::cout << number[i];
		}
	}
	std::cout << "\t";
}

void print1ToMaxOfDigitsRecursively(char *number, int length, int index)
{
	if (index == length - 1)
	{
		printNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		print1ToMaxOfDigitsRecursively(number, length, index + 1);
	}
}

void print1ToMaxOfNDigits2(int n)
{
	if (n <= 0)
	{
		return;
	}
	char *number = new char[n + 1];
	number[n] = '\0';
	for (int i=0; i<10; ++i)
	{
		number[0] = i + '0';
		print1ToMaxOfDigitsRecursively(number, n, 0);
	}
	delete []number;
}

// 方法三
void PrintNumber2(const string& number)
{
	bool isBegin0 = true;
	for (int i=0; i<number.size(); i++)
	{
		if (isBegin0 && number[i] != '0')
		{
			isBegin0 = false;
		}
		if (!isBegin0)
		{
			std::cout << number[i];
		}
	}
	std::cout << '\t';
}

void print1ToNDigits(string number, int length, int index)
{
	if (index == length)
	{
		PrintNumber2(number);
		return;
	}
	for (int i=0; i<10; i++)
	{
		number[index] = i + '0';
		print1ToNDigits(number, length, index + 1);
	}
}

void print1ToNMaxNum3(int n)
{
	if (n <= 0)
	{
		return;
	}

	string numStr(n, '0');
	print1ToNDigits(numStr, n, 0);
}

int main()
{
	// print1ToMaxOfNDigits2(3);
	print1ToNMaxNum3(4);
    std::cout << "Hello World!\n";
}
