#include "s.h"
/*
 * @lc app=leetcode.cn id=1857 lang=cpp
 *
 * [1857] 有向图中最大颜色值
 */

// @lc code=start
class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        int m = edges.size();

        vector<vector<int>> Adj(n);
        vector<int> inDegree(n);

        unordered_map<char, int> color2index;

        int a = 0;
        for (int i = 0; i < n; i++)
        {
            if (color2index.count(colors[i]) == 0)
            {
                color2index[colors[i]] = a++;
            }
        }
        vector<vector<int>> f(n, vector<int>(a));

        for (int i = 0; i < m; i++)
        {
            Adj[edges[i][0]].push_back(edges[i][1]);
            inDegree[edges[i][1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int cnt = 0;
        int ans = -1;

        while (!q.empty())
        {

            cnt++;
            int node = q.front();
            q.pop();

            f[node][color2index[colors[node]]]++;
            ans = max(f[node][color2index[colors[node]]], ans);

            for (auto nnode : Adj[node])
            {
                inDegree[nnode]--;
                if (inDegree[nnode] == 0)
                {
                    q.push(nnode);
                }
                for (int j = 0; j < a; j++)
                {
                    f[nnode][j] = max(f[nnode][j], f[node][j]);
                }
            }
        }

        if (cnt != n)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};
// @lc code=end

int main()
{

    Solution s;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {2, 3},
        {3, 4},
        {4, 0}};
    vector<vector<int>> edges2 = {
        {0, 0}};

    vector<vector<int>> edges3 = {
        {{0, 1}, {0, 2}, {2, 3}, {3, 4}, {3, 5}, {5, 6}, {2, 7}, {6, 7}, {7, 8}, {3, 8}, {5, 8}, {8, 9}, {3, 9}, {6, 9}}};

    cout << s.largestPathValue("abaca", edges);
    cout << s.largestPathValue("a", edges2);
    cout << s.largestPathValue("hhqhuqhqff", edges3);

    return 0;
}