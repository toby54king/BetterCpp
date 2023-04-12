// convertBinarySearchTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 二叉搜索树与双向链表

#include <iostream>

struct BinaryTreeNode 
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode *convert(BinaryTreeNode *pRootOfTree)
{
	BinaryTreeNode *pLastNodeInList = nullptr;
	convertNode(pRootOfTree, &pLastNodeInList);
	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
	{
		pHeadOfList = pHeadOfList->m_pLeft;
	}

	return pHeadOfList;
}

void convertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList)
{
	if (pNode == nullptr)
		return;

	BinaryTreeNode *pCurrent = pNode;
	if (pCurrent->m_pLeft != nullptr)
	{
		convertNode(pCurrent->m_pLeft, pLastNodeInList);
	}

	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != nullptr)
	{
		(*pLastNodeInList)->m_pRight = pCurrent;
	}
	*pLastNodeInList = pCurrent;
	if (pCurrent->m_pLeft != nullptr)
	{
		convertNode(pCurrent->m_pRight, pLastNodeInList);
	}
}

int main()
{
    std::cout << "Hello World!\n";
}
