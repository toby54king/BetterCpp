// reorderArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 调整数组顺序使奇数位于偶数前面

#include <iostream>

void recordOddEven(int *pData, unsigned int length)
{
	if (pData == nullptr || length == 0)
	{
		return;
	}

	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		while (pBegin<pEnd && (*pBegin & 0x1) != 0)
		{
			pBegin++;
		}

		while (pBegin<pEnd && (*pEnd & 0x1) == 0)
		{
			pEnd--;
		}

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

void reorder(int *pData, unsigned int length, bool (*func)(int))
{
	if (pData == nullptr || length == 0)
	{
		return;
	}

	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
		{
			pBegin++;
		}

		while (pBegin < pEnd && func(*pEnd))
		{
			pEnd--;
		}

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n)
{
	return (n & 1) == 0;
}

void recordOddEven2(int *pData, unsigned int length)
{
	reorder(pData, length, isEven);
}

int main()
{
    std::cout << "Hello World!\n";
}