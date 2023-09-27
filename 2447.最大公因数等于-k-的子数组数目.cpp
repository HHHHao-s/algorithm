#include "s.h"
/*
 * @lc app=leetcode.cn id=2447 lang=cpp
 *
 * [2447] 最大公因数等于 K 的子数组数目
 */

// @lc code=start
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(x%k!=0){
                continue;
            }
            int g = x;
            for(int j=i;j<n;j++){
                g = gcd<int>(g, nums[j]);
                if(g==k){
                    ans++;
                }   
            }
        }
        return ans;
    }
};
// @lc code=end

