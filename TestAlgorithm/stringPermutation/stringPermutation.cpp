// stringPermutation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 字符串的排列

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void permutation(char *pStr)
{
	if (pStr == nullptr)
	{
		return;
	}

	permutation(pStr, pStr);
}

void permutation(char *pStr, char *pBegin)
{
	if (*pBegin == '\0')
	{
		std::cout << pStr << std::endl;
	} 
	else
	{
		for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			permutation(pStr, pBegin + 1);
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

class Solution
{
public:
	std::vector<string> permutation(string s)
	{
		dfs(s, 0);
		return res;
	}

private:
	std::vector<string> res;
	void dfs(string s, int x)
	{
		if (x == s.size()-1)
		{
			res.push_back(s);
			return;
		}

		std::set<int> st;
		for (int i=x; i<s.size(); i++)
		{
			if (st.find(s[i]) != st.end())
			{
				continue;
			}
			st.insert(s[i]);
			swap(s[i], s[x]);
			dfs(s, x + 1);
			swap(s[i], s[x]);
		}
	}
};


int main()
{
    std::cout << "Hello World!\n";
}
