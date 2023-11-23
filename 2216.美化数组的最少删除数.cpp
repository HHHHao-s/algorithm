#include "s.h"
/*
 * @lc app=leetcode.cn id=2216 lang=cpp
 *
 * [2216] 美化数组的最少删除数
 */

// @lc code=start
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=1;i<n;i+=2){
            if(nums[i]==nums[i-1]){
                ans++;
                i--;
            }
        }
        if((n-ans)%2==1){
            return ans+1;
        }
        return ans;

    }
};
// @lc code=end

