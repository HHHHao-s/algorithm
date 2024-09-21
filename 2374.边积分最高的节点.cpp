#include "s.h"
/*
 * @lc app=leetcode.cn id=2374 lang=cpp
 *
 * [2374] 边积分最高的节点
 */

// @lc code=start
class Solution {
public:
    using ll = long long;
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<ll> points(n);
        for (int i = 0; i < n; i++) {
            points[edges[i]] += i;
        }
        ll max_points = -1;
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (points[i] > max_points) {
                max_points = points[i];
                res = i;
            }
        }
        return res;
    }
};
// @lc code=end

