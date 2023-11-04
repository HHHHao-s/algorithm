#include "s.h"
/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        for(int k=30;k>=0;k--){
            unordered_set<int> seen;
            for(int num:nums){
                seen.insert(num>>k);

            }

            int x_next = (x<<1) +1;
            bool found=false;
            for(int num:nums){
                if(seen.count(x_next ^(num>>k))){
                    found=true;
                    break;
                }
            }

            if(found){
                x = x_next;
            }else{
                x = x_next-1;
            }
        }
        return x;

    }
};
// @lc code=end

