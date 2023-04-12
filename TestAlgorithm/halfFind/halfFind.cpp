// halfFind.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//折半查找要求查找的数据必须是有序的，选取中间的数据作为基数，
//将数据分成两部分与关键字进行比较，如果关键字大于基数则在基数
//右半部分查找（此处按升序排列），否则在左半部分查找

#include <iostream>
using namespace std;

// 递归查找
template <typename T>
int half_find(T data[],int left, int right,T target)
{
	if (left > right)
		return -1;

	int mid = left + (right - left) / 2;// 防止整数溢出
	if (data[mid] > target)
	{
		return half_find(data, left, mid - 1, target);
	}
	else if (data[mid] < target)
	{
		return half_find(data, mid + 1, right, target);
	}
	else
	{
		return mid;
	}
}

// 非递归查找
template <typename T>
int half_find_T(T data[], int n, T target)
{
	int left = 0;
	int right = n - 1;
	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if (data[mid] > target)
		{
			right = mid - 1;
		}
		else if (data[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
    std::cout << "Hello World!\n";
}