#include "s.h"
/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 寻找峰值 II
 */

// @lc code=start
class Solution {
    int indexOfMax(vector<int> &a) {
        return max_element(a.begin(), a.end()) - a.begin();
    }

public:
    vector<int> findPeakGrid(vector<vector<int>> &mat) {
        int left = 0, right = mat.size() - 2;
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = indexOfMax(mat[i]);
            if (mat[i][j] > mat[i + 1][j]) {
                right = i - 1; // 峰顶行号 <= i
            } else {
                left = i + 1; // 峰顶行号 > i
            }
        }
        return {left, indexOfMax(mat[left])};
    }
};
// @lc code=end

