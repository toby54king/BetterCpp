// reverseList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 

#include <iostream>
struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;
};

ListNode *reverseList(ListNode *pHead)
{
	ListNode *pReverseHead = nullptr;
	ListNode *pCur = pHead;
	ListNode *pPrev = nullptr;
	while (pCur != nullptr)
	{
		ListNode *pNext = pCur->m_pNext;
		if (pNext == nullptr)
		{
			pReverseHead = pCur;
		}
		pCur->m_pNext = pPrev;
		pPrev = pCur;
		pCur = pNext;
	}
	return pReverseHead;
}

int main()
{
    std::cout << "Hello World!\n";
}