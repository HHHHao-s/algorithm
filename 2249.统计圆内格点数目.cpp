#include "s.h"
/*
 * @lc app=leetcode.cn id=2249 lang=cpp
 *
 * [2249] 统计圆内格点数目
 */

// @lc code=start
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        /* 遍历坐标系中的所有点，根据圆的方程过滤出落在圆上面的点 */
        int result = 0;
        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                for (auto& circle : circles) {
                    int x = circle[0], y = circle[1], r = circle[2];
                    /* 圆心为(a,b) 半径为r的圆的方程为(x-a)²+(x-b)²=r² */
                    if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r) {
                        result++;
                        break;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

