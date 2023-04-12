// minNumberInRotatedArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 旋转数组的最小数字
// 

#include <iostream>
#include <vector>
using namespace std;

int Min(int *numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return 0;
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (numbers[indexMid] >= numbers[index1])
		{
			index1 = indexMid;
		}
		else if (numbers[indexMid] <= numbers[index2])
		{
			index2 = indexMid;
		}
	}
	return numbers[indexMid];
}

class MyClass
{
public:
	int minArray(std::vector<int> &numbers)
	{
		int low = 0;
		int high = numbers.size();
		while (low < high)
		{
			int mid = low + (high - low) / 2;
			if (numbers[mid] < numbers[high])
			{
				high = mid;
			}
			else if (numbers[mid] > numbers[high])
			{
				low = mid + 1;
			}
			else
			{
				high -= 1;
			}
		}
		return numbers[low];
	}
};

int main()
{
    std::cout << "Hello World!\n";
}