// buildBinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 重建二叉树，根据前序和后序结果
// 

#include <iostream>

struct BinaryTreeNode 
{
	int m_nvalue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode* Construct(int *preorder, int *inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length == 0)
	{
		return nullptr;
	}
	return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BinaryTreeNode* ConstructCore(int *sPreorder, int *ePreorder, int *sInorder, int *eInorder)
{
	int rootValue = sPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nvalue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;
	if (sPreorder == ePreorder && sInorder == eInorder && *sPreorder == *sInorder)
	{
		return root;
	}

	// 在中序遍历中找到根节点的值
	int *rootInorder = sInorder;
	while (rootInorder <= eInorder && *rootInorder != rootValue)
	{
		++rootInorder;
	}

	int leftLength = rootInorder - sInorder;
	int *leftPreorderEnd = sPreorder + leftLength;
	if (leftLength>0)
	{
		root->m_pLeft = ConstructCore(sPreorder + 1, leftPreorderEnd, sInorder,rootInorder-1);
	} 
	if (leftLength<ePreorder-sPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, ePreorder, rootInorder + 1, eInorder);
	}
	return root;
}

int main()
{
    std::cout << "Hello World!\n";
}