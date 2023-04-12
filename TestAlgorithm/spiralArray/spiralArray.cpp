// spiralArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/spiral-matrix/solution/luo-xuan-ju-zhen-by-leetcode-solution/
// 螺旋数组
// 输入：matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
// 输出：[1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]

// 输入：matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
// 输出：[1, 2, 3, 6, 9, 8, 7, 4, 5]

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralArray(vector<vector<int>> &matrix)
{
	if (matrix.empty())
	{
		return vector<int>{};
	}
	vector<int> res;
	int rows = matrix.size(), cols = matrix[0].size();
	int l = 0, r = cols - 1, t = 0, b = rows - 1;
	while (l<=r && t<=b)
	{
		for (int col = l; col <= r; col++)
		{
			res.emplace_back(matrix[t][col]);
		}
		for (int row=t+1; row<=b; row++)
		{
			res.emplace_back(matrix[row][r]);
		}
		if (l<r && t<b)
		{
			for (int col=r-1; col>l; col--)
			{
				res.emplace_back(matrix[b][col]);
			}
			for (int row=b; row>t; row--)
			{
				res.emplace_back(matrix[row][l]);
			}
		}
		l++;
		r--;
		t++;
		b--;
	}
	return res;
}

int main()
{
	vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	vector<int> res = spiralArray(matrix);
	for (int i=0; i<res.size(); i++)
	{
		std::cout << res[i] << std::endl;
	}
    std::cout << "Hello World!\n";
}