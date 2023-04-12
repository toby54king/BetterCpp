// verifySquenceOfBst.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 二叉搜索树的后序遍历序列

#include <iostream>

bool verifySquenceOfBst(int sequence[], int length)
{
	if (sequence == nullptr || length<=0)
	{
		return false;
	}

	int root = sequence[length - 1];
	int i = 0; 
	for (; i<length-1; ++i)
	{
		if (sequence[i]>root)
		{
			break;
		}
	}

	int j = i;
	for (; j<length-1; ++j)
	{
		if (sequence[j]<root)
		{
			return false;
		}
	}

	bool left = true;
	if (i > 0)
	{
		left = verifySquenceOfBst(sequence, i);
	}

	bool right = true;
	if (i<length-1)
	{
		right = verifySquenceOfBst(sequence + i, length - i - 1);
	}

	return left && right;
}

int main()
{
    std::cout << "Hello World!\n";
}
