#include "s.h"
#include <functional>
#include <vector>
/*
 * @lc app=leetcode.cn id=3820 lang=cpp
 *
 * [3820] 树上的勾股距离节点
 */

// @lc code=start
class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int v = e[0], w = e[1];
            g[v].push_back(w);
            g[w].push_back(v);
        }

        auto calc_dis = [&](int start) -> vector<int> {
            vector<int> dis(n);
            auto dfs = [&](this auto&& dfs, int v, int fa) -> void {
                for (int w : g[v]) {
                    if (w != fa) {
                        dis[w] = dis[v] + 1;
                        dfs(w, v);
                    }
                }
            };
            dfs(start, -1);
            return dis;
        };

        auto dx = calc_dis(x);
        auto dy = calc_dis(y);
        auto dz = calc_dis(z);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> a = {dx[i], dy[i], dz[i]};
            ranges::sort(a);
            if (1LL * a[0] * a[0] + 1LL * a[1] * a[1] == 1LL * a[2] * a[2]) {
                ans++;
            }
        }
        return ans;
    }
};

// @lc code=end

