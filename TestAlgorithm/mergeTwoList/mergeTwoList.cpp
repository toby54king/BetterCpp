// mergeTwoList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 合并两个排序的链表

#include <iostream>

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
	ListNode(int val) : m_nValue(val) {}
};

ListNode *merge(ListNode *pHead1, ListNode *pHead2)
{
	if (pHead1 == nullptr)
	{
		return pHead2;
	}
	else if (pHead2 == nullptr)
	{
		return pHead1;
	}

	ListNode *pMergeHead = nullptr;
	if (pHead1->m_nValue < pHead2->m_nValue)
	{
		pMergeHead = pHead1;
		pMergeHead->m_pNext = merge(pHead1->m_pNext, pHead2);
	} 
	else
	{
		pMergeHead = pHead2;
		pMergeHead->m_pNext = merge(pHead1, pHead2->m_pNext);
	}
	return pMergeHead;
}

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode *preHead = new ListNode(-1);
	ListNode *pre = preHead;
	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->m_nValue < l2->m_nValue)
		{
			pre->m_pNext = l1;
			l1 = l1->m_pNext;
		} 
		else
		{
			pre->m_pNext = l2;
			l2 = l2->m_pNext;
		}
	}

	pre->m_pNext = l1 == nullptr ? l2 : l1;
	return preHead;
}


int main()
{
    std::cout << "Hello World!\n";
}
