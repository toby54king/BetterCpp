// ListNode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 

#include <iostream>

struct ListNode 
{
	int m_nValue;
	ListNode *m_pNext;
};

// 在链表尾部加入一个数
void addToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode;
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	} 
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

// 删除链表中的一个数值
void removeNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}
	ListNode* pToBeDeleted = *pHead;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}
		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

int main()
{
    std::cout << "Hello World!\n";
}

