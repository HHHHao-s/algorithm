#include "s.h"
/*
 * @lc app=leetcode.cn id=1276 lang=cpp
 *
 * [1276] 不浪费原料的汉堡制作方案
 */

// @lc code=start
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int less = cheeseSlices*2;
        int mx = cheeseSlices*4;
        if(tomatoSlices<less || tomatoSlices>mx){
            return {};
        }
        int big = tomatoSlices-2*cheeseSlices;
        if(big%2==1){
            return {};
        }
        big/=2;
        return {big, cheeseSlices-big};
    }
};
// @lc code=end

