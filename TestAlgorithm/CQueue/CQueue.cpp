// CQueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 用两个栈实现一个队列

#include <iostream>

template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue();

	void appendTail(const T& element);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.size()<=0)
	{
		while (stack1.size()>0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0)
	{
		throw new exception("queue is empty!");
	}

	T head = stack2.top();
	stack2.pop();
	return head;
}

int main()
{
    std::cout << "Hello World!\n";
}