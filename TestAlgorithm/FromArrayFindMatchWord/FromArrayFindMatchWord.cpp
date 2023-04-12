// FromArrayFindMatchWord.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
	// s记录words中出现的单词，t记录已经搜索到的单词
	unordered_set<string> s, t;
	// ret为结果数组
	vector<string> ret;
	// 全局变量，拷贝board
	vector<vector<char>> ch;
	//  网格的行列数
	int n, m;
	// 搜索方向
	int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
	// 深度优先搜索，i,j为位置，cur为当前组好的字符串，vis为标记数组
	void dfs(int i, int j, string cur, vector<vector<bool>>& vis)
	{
		// 剪枝，如果当前字符串的长度大于10，直接返回，因为不会出现在words
		if (cur.size() > 10) return;

		// 如果当前字符串在words中出现过，记录在结果中
		if (s.count(cur))
		{
			t.insert(cur);
		}

		for (int k=0; k<4; k++)
		{
			// 向四个方向走一步，保证新的位置在网格内，且本分支没有被遍历过
			int xx = i + dx[k], yy = j + dy[k];
			if (xx > 0 && xx < n && yy>=0 && yy < m && !vis[xx][yy])
			{
				// 标记为true, 防止重复利用
				vis[xx][yy] = true;
				dfs(xx, yy, cur + ch[xx][yy], vis);
				// 标记为false
				vis[xx][yy] = false;
			}
		}

		return;
	}

	// 查找单词
	vector<string> findWords(vector<vector<char>> &board, vector<string>& words)
	{
		// 初始化
		for (string w : words)
		{
			s.insert(w);
		}
		ch = board;
		n = board.size(), m = board[0].size();

		// 声明空字符串，用于第一步的搜索
		string s;
		vector<vector<bool>> vis(n, vector<bool>(m));
		
		// 从所有位置开始搜索
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				vis[i][j] = true;
				dfs(i, j, s + board[i][j], vis);
				vis[i][j] = false;
			}
		}

		for (string tt : t) ret.emplace_back(tt);
		return ret;
	}

};

int main()
{
    std::cout << "Hello World!\n";
}