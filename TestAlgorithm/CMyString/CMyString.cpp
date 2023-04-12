// CMyString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char *pData = nullptr);
	CMyString(const CMyString &str);
	~CMyString();

private:
	char *m_pData;
};

#if 0
// 初级程序员写法
CMyString& CMyString::operator=(const CMyString &str)
{
	if (this == &str)
	{
		return *this;
	}

	delete[] m_pData;
	m_pData = nullptr;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}
#endif

// 高级程序员写法
CMyString& CMyString::operator = (const CMyString &str)
{
	if (this != &str)
	{
		CMyString strTemp(str);
		char * pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}

int main()
{
    std::cout << "Hello World!\n";
}
