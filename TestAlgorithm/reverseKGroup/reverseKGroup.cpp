// reverseKGroup.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
K 个一组反转链表
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode():val(0),next(nullptr){}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x, ListNode *next):val(x),next(next){}
};

ListNode* reverseList(ListNode *a, ListNode *b)
{
	ListNode *pre, *cur, *nxt;
	pre = nullptr; cur = a; nxt = a;
	while (cur != b)
	{
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}
	return pre;
}

ListNode* reverseKGroup(ListNode *head, int k)
{
	if (head == nullptr)
	{
		return nullptr;
	}
	ListNode *a, *b;
	a = b = head;
	for (int i=0; i<k; i++)
	{
		if (b == nullptr)
		{
			return head;
		}
		b = b->next;
	}
	ListNode *newHead = reverseList(a, b);
	a->next = reverseKGroup(b, k);
	return newHead;
}

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = nullptr;

	ListNode *phead = reverseKGroup(head,2);
	
	std::cout << phead->val << std::endl;
	std::cout << phead->next->val << std::endl;
	std::cout << phead->next->next->val << std::endl;
	std::cout << phead->next->next->next->val << std::endl;
	std::cout << phead->next->next->next->next->val << std::endl;
	std::cout << phead->next->next->next->next->next->val << std::endl;
	
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
