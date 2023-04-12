// printFromTopToBottom.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 从上往下打印二叉树

#include <iostream>
#include <deque>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void printFromTopToBottom(BinaryTreeNode *pRoot)
{
	if (!pRoot)
	{
		return;
	}

	std::deque<BinaryTreeNode*> dequeTreeNodes;
	dequeTreeNodes.push_back(pRoot);

	while (dequeTreeNodes.size())
	{
		BinaryTreeNode *pNode = dequeTreeNodes.front();
		dequeTreeNodes.pop_front();
		std::cout << pNode->m_nValue;

		if (pNode->m_pLeft)
		{
			dequeTreeNodes.push_back(pNode->m_pLeft);
		}

		if (pNode->m_pRight)
		{
			dequeTreeNodes.push_back(pNode->m_pRight);
		}
	}
}

int main()
{
    std::cout << "Hello World!\n";
}