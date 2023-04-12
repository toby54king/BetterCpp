// arrayFind.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//在一个二维数组中查找一个数，该二维数组从左到右，从上到下都是递增的

#include <iostream>
using namespace std;

bool findNumInArray(int *data, int rows, int cols, const int num)
{
	bool isFind = false;
	if (data != nullptr && rows>0 && cols>0)
	{
		int row = 0;
		int col = cols - 1;
		while (row<rows && col >=0)
		{
			if (data[row*cols+col] == num)
			{
				isFind = true;
				break;
			} 
			else if(data[row*cols+col] > num)
			{
				col--;
			}
			else
			{
				row++;
			}
		}
	}
	return isFind;
}

int main()
{
	int matrix[][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	bool isFind = findNumInArray((int*)matrix,4,4,7);
	if (isFind)
	{
		std::cout << "isFind!" << std::endl;
	}
	else
	{
		std::cout << "not find!" << std::endl;
	}
    std::cout << "Hello World!\n";
}
