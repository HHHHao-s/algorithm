#include "s.h"
/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        int prefix=1, surfix=1;

        vector<int>ans(n,1);
        
        

        for(int i=0;i<n;i++){
            ans[i]*= prefix;
            ans[n-i-1] *= surfix;
            prefix*=nums[i];
            surfix*=nums[n-1-i];
        }


        return ans;

    }
};
// @lc code=end

