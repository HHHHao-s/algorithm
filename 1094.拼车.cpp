#include "s.h"
/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1010);
        for(auto &trip: trips){
            diff[trip[1]]+=trip[0];
            diff[trip[2]]-=trip[0];
        }
        int have = 0;
        for(int i=0;i<=1000;i++){
            have+=diff[i];
            if(have>capacity){
                return false;
            } 
        }
        return true;

    }
};
// @lc code=end

