#include "s.h"
/*
 * @lc app=leetcode.cn id=885 lang=cpp
 *
 * [885] 螺旋矩阵 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int n = rows * cols;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res;
        res.reserve(n);
        res.push_back({rStart, cStart});
        int d = 0, step = 1;
        int r = rStart, c = cStart;
        while (true) {
            for (int i = 1; i <= step; i++) {
                r = r + dir[d][0];
                c = c + dir[d][1];
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    res.push_back({r, c});
                }
            }
            if (res.size() == n) {
                return res;
            }
            d = (d + 1) % 4;
            if (d % 2 == 0) {
                step++;
            }
        }
        return res;
    }
};
// @lc code=end

