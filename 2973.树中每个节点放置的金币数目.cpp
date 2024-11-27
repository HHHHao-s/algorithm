#include "s.h"
/*
 * @lc app=leetcode.cn id=2973 lang=cpp
 *
 * [2973] 树中每个节点放置的金币数目
 */

// @lc code=start
class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> g(n);
        for (auto& e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<long long> ans(n, 1);
        auto dfs = [&](auto&& dfs, int x, int fa) -> vector<int> {
            vector<int> a = {cost[x]};
            for (int y: g[x]) {
                if (y != fa) {
                    auto res = dfs(dfs, y, x);
                    a.insert(a.end(), res.begin(), res.end());
                }
            }
            ranges::sort(a);
            int m = a.size();
            if (m >= 3) {
                ans[x] = max(max((long long) a[m - 3] * a[m - 2] * a[m - 1], (long long) a[0] * a[1] * a[m - 1]), 0LL);
            }
            if (m > 5) {
                a = {a[0], a[1], a[m - 3], a[m - 2], a[m - 1]};
            }
            return a;
        };
        dfs(dfs, 0, -1);
        return ans;
    }
};

// @lc code=end

