#include "s.h"
/*
 * @lc app=leetcode.cn id=2552 lang=cpp
 *
 * [2552] 统计上升四元组
 */

// @lc code=start
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> pre(n+1);
        for(int i=nums[0]+1;i<=n;i++){

            pre[i]++;

        }
        long long ret=0;
        long long suf= 0;
        for(int j=1;j<n-2;j++){
            suf = nums[n-1]>nums[j];

            for(int k=n-2;k>j;k--){
                if(nums[k]<nums[j]){
                    ret += pre[nums[k]]*suf;
                }
                suf += nums[k]>nums[j];
            }

            for(int i=nums[j]+1;i<=n;i++){
                pre[i]++;
            }

        }

        return ret;


    }   
};
// @lc code=end

