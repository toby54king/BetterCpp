// findKthToTail.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 链表中倒数第K个结点

#include <iostream>

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

// 方法一，有问题
ListNode *findKthToTail(ListNode *pListHead, unsigned int k)
{
	ListNode *pAhead = pListHead;
	ListNode *pBehind = nullptr;
	for (unsigned int i=0; i<k-1; ++i)
	{
		pAhead = pAhead->m_pNext;
	}
	pBehind = pListHead;
	while (pAhead->m_pNext != nullptr)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}

// 方法二，改进版
ListNode *findKthToTail2(ListNode *pListHead, unsigned int k)
{
	if (pListHead == nullptr || k==0)
	{
		return nullptr;
	}

	ListNode *pAhead = pListHead;
	ListNode *pBehind = nullptr;

	for (unsigned int i=0; i<k-1; ++i)
	{
		if (pAhead->m_pNext != nullptr)
		{
			pAhead = pAhead->m_pNext;
		} 
		else
		{
			return nullptr;
		}
	}
	pBehind = pListHead;
	while (pAhead->m_pNext != nullptr)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}

ListNode *getKthFromEnd(ListNode *head, int k)
{
	int len = 0;
	ListNode *node = nullptr;
	node = head;
	while (node)
	{
		node = node->m_pNext;
		len++;
	}

	while (head && len>k)
	{
		head = head->m_pNext;
		len--;
	}
	return head;
}

int main()
{
    std::cout << "Hello World!\n";
}
