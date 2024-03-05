#include "s.h"
/*
 * @lc app=leetcode.cn id=2662 lang=cpp
 *
 * [2662] 前往目标的最小代价
 */

// @lc code=start
class Solution {
public:
    int minimumCost(vector<int> &start, vector<int> &target, vector <vector<int>> &specialRoads) {
        using LL = long long;
        LL t = (LL) target[0] << 32 | target[1];
        unordered_map<LL, int> dis = {{(LL) start[0] << 32 | start[1], 0}, {t, INT_MAX}};
        unordered_set<LL> vis;
        for (;;) {
            LL v = -1;
            int dv = -1;
            for (auto &[p, d]: dis)
                if (!vis.count(p) && (dv < 0 || d < dv))
                    v = p, dv = d;
            if (v == t) return dv; // 到终点的最短路已确定
            vis.insert(v);
            int vx = v >> 32, vy = v & UINT32_MAX;
            // 更新到终点的最短路
            dis[t] = min(dis[t], dv + target[0] - vx + target[1] - vy);
            for (auto &r: specialRoads) {
                int d = dv + abs(r[0] - vx) + abs(r[1] - vy) + r[4];
                LL w = (LL) r[2] << 32 | r[3];
                if (!dis.count(w) || d < dis[w])
                    dis[w] = d;
            }
        }
    }
};

// @lc code=end

int main(){
    Solution s;
    // vector<int> start = {3,2}, target={5,7};
    // vector<vector<int>> sp = {{3,2,3,4,4},{3,3,5,5,5},{3,4,5,6,6}};

    vector<int> start = {1,1}, target={1,3};
    vector<vector<int>> sp = {{1,1,1,3,1},{1,2,1,1,2},{1,1,1,3,4},{1,3,1,2,5},{1,2,1,3,4}};

    cout << s.minimumCost(start, target,sp);
}