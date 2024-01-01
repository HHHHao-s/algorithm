#include "s.h"
/*
 * @lc app=leetcode.cn id=2543 lang=cpp
 *
 * [2543] 判断一个点是否可以到达
 */

// @lc code=start
class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int g = gcd(targetX, targetY);
        return (g&(g-1))==0; // gcd 是2的幂次


    }
};
// @lc code=end

