// stringTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 为了节省内存，C++把常量字符串放到单独的一个内存区域，当几个指针赋值给
// 相同的常量字符串时，它们实际上会指向相同的内存地址,但是用常量初始化数组情况却不一样

#include <iostream>

void testStr()
{
	char str1[] = "hello world";
	char str2[] = "hello world";

	char *str3 = (char*)"hello world";
	char *str4 = (char*)"hello world";

	if (str1 == str2)
	{
		std::cout << "str1 and str2 are same!\n";
	}
	else
	{
		std::cout << "str1 and str2 are not same!\n";
	}

	if (str3 == str4)
	{
		std::cout << "str3 and str4 are same!\n";
	}
	else
	{
		std::cout << "str3 and str4 are not same!\n";
	}
}

int main()
{
	testStr();
    std::cout << "Hello World!\n";
}

