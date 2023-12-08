#include "s.h"
/*
 * @lc app=leetcode.cn id=2503 lang=cpp
 *
 * [2503] 矩阵查询可获得的最大分数
 */

// @lc code=start
class Solution {
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        // 查询的下标按照查询值从小到大排序，方便离线
        int k = queries.size(), id[k];
        iota(id, id + k, 0);
        sort(id, id + k, [&](int i, int j) { return queries[i] < queries[j]; });

        vector<int> ans(k);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // 最小堆
        pq.emplace(grid[0][0], 0, 0);
        grid[0][0] = 0; // 充当 vis 数组的作用
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        for (int qi : id) {
            int q = queries[qi];
            while (!pq.empty() && get<0>(pq.top()) < q) {
                ++cnt;
                auto[_, i, j] = pq.top();
                pq.pop();
                for (auto &d : dirs) { // 枚举周围四个格子
                    int x = i + d[0], y = j + d[1];
                    if (0 <= x && x < m && 0 <= y && y < n && grid[x][y]) {
                        pq.emplace(grid[x][y], x, y);
                        grid[x][y] = 0; // 充当 vis 数组的作用
                    }
                }
            }
            ans[qi] = cnt;
        }
        return ans;
    }
};
// @lc code=end

int main(){

    Solution s;
    vector<vector<int>>grid ={
        {1,2,3},
        {2,5,7},
        {3,5,1}
    };
    vector<int> queries = {5,6,2};
    printArr( s.maxPoints(grid, queries));
}