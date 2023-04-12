// deleteNodeList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 在O(1)时间删除链表结点

#include <iostream>

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

void deleteNode(ListNode **pListHead, ListNode *pToDeleted)
{
	if (!pListHead || !pToDeleted)
	{
		return;
	}

	if (pToDeleted->m_pNext != nullptr)
	{
		ListNode *pNext = pToDeleted->m_pNext;
		pToDeleted->m_nValue = pNext->m_nValue;
		pToDeleted->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = nullptr;
	}
	else if (*pListHead == pToDeleted)
	{
		delete pToDeleted;
		pToDeleted = nullptr;
		*pListHead = nullptr;
	}
	else
	{
		ListNode *pNode = *pListHead;
		while (pNode->m_pNext != pToDeleted)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = nullptr;
		delete pToDeleted;
		pToDeleted = nullptr;
	}
}

int main()
{
    std::cout << "Hello World!\n";
}