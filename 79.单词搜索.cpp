#include "s.h"
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
public:
    bool dfs(vector<vector<bool>> &visited, const vector<vector<char>> &board, string word, int cur, int x, int y, int n)
    {
        if (cur == n)
        {
            return 1;
        }
        if (x < 0 || y < 0 || x >= board[0].size() || y >= board.size())
            return 0;
        if (visited[y][x])
            return 0;

        if (board[y][x] == word[cur])
        {
            visited[y][x] = 1;
            bool ret = dfs(visited, board, word, cur + 1, x + 1, y, n) || dfs(visited, board, word, cur + 1, x, y + 1, n) || dfs(visited, board, word, cur + 1, x - 1, y, n) || dfs(visited, board, word, cur + 1, x, y - 1, n);
            visited[y][x] = 0;
            return ret;
        }
        return false;
    }

    bool exist(const vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                bool ret = dfs(visited, board, word, 0, j, i, word.size());
                // visited[i][j]=1;
                if (ret == true)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.exist({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCB");


    return 0;
}