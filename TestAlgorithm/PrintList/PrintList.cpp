// PrintList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 从尾到头打印链表

#include <iostream>
#include <stack>

struct ListNode 
{
	int m_nKey;
	int m_nValue;
	ListNode* m_pNext;
};

// 使用栈stack
void printListReverse(ListNode *pHead)
{
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		std::cout << pNode->m_nValue;
		nodes.pop();
	}
}

// 使用递归,当链表太长时，会出现栈溢出的现象，方法一鲁棒性更好点
void printListReverse2(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			printListReverse2(pHead->m_pNext);
		}
		std::cout << pHead->m_nValue;
	}
}

int main()
{
    std::cout << "Hello World!\n";
}