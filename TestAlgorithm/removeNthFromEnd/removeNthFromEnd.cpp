// removeNthFromEnd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

#if 0
输入：head = [1, 2, 3, 4, 5], n = 2
输出：[1, 2, 3, 5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1, 2], n = 1
输出：[1]
#endif

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode():val(0),next(nullptr){}
	ListNode(int x) : val(x),next(nullptr){}
	ListNode(int x, ListNode *next) : val(x), next(nullptr) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{

}

int main()
{
    std::cout << "Hello World!\n";
}
