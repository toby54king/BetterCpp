// pathinTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 二叉树中和为某一值的路径



#include <iostream>
#include <vector>

struct BinaryTreeNode
{
	int m_val;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void findPath(BinaryTreeNode *pRoot, int expectedSum)
{
	if (pRoot == nullptr)
	{
		return;
	}

	std::vector<int> path;
	int curSum = 0;
	findPath(pRoot, expectedSum, path, curSum);
}

void findPath(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int &curSum)
{
	curSum += pRoot->m_val;
	path.emplace_back(pRoot->m_val);

	bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
	if (curSum == expectedSum && isLeaf)
	{
		std::vector<int>::iterator iter = path.begin();
		for (; iter!= path.end(); ++iter)
		{
			std::cout << *iter << std::endl;
		}
	}

	if (pRoot->m_pLeft != nullptr)
	{
		findPath(pRoot->m_pLeft, expectedSum, path, curSum);
	}
	if (pRoot->m_pRight != nullptr)
	{
		findPath(pRoot->m_pRight, expectedSum, path, curSum);
	}

	curSum -= pRoot->m_val;
	path.pop_back();
}

int main()
{
    std::cout << "Hello World!\n";
}