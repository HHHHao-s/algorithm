#include "s.h"
/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int all=0;
        for(int i=0;i<nums.size();i++){
            all ^= nums[i];
        }

        // 取最后一位将两组数区分
        int test = all==INT_MIN?all:(all&(-all));
        int type1 = 0,type2=0;
        for(int num:nums){
            if(test & num){
                type1^=num;
            }else{
                type2^=num;
            }
        }
        return {type1, type2};

    }
};
// @lc code=end

