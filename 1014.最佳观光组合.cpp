#include "s.h"
/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ret=0;
        int mx = values[0]+0;
        for(int i=1;i<values.size();i++){
            ret = max(ret,mx+ (values[i]-i));
            mx = max(values[i]+i, mx);


        }
        return ret;


    }
};
// @lc code=end

