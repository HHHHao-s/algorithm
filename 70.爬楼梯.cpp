#include "s.h"
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }else if(n == 2){
            return 2;
        }

        int before1 = 1, before2 = 2;

        for(int i=3;i<n;i++){
            int x = before1 + before2;
            before1 = before2;
            before2 = x;
        }

        return before1 + before2; 

    }
};
// @lc code=end

