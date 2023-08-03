#include "s.h"
/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l = 1;
        int r = n-1;
        int ans = -1;
        while(l<=r){
            int center = (l+r)/2;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(nums[i]<=center){
                    cnt++;
                }
            }
            if(cnt>center){// 在小端
                r = center-1;
                ans = center;
            }else{
                l = center+1;
            }
        }
        return ans;
    }
};
// @lc code=end

