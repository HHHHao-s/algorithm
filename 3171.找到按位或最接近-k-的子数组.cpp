#include "s.h"
/*
 * @lc app=leetcode.cn id=3171 lang=cpp
 *
 * [3171] 找到按位或最接近 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        vector<int> arr;
        int n = nums.size();
        int ans =INT_MAX;
        for(int i=0;i<n;i++){

            
            for(int j=0;j<arr.size();j++){
                arr[j] |= nums[i];
                ans = min(abs(k-arr[j]),ans);
            }
            
            arr.push_back(nums[i]);
            ans = min(abs(k-arr.back()),ans);
            int t=0;
            for(int j=1;j<arr.size();j++){
                if(arr[t]!=arr[j]){
                    t++;
                }
                arr[t]=arr[j];
            }
            arr.resize(t+1);

        }
        return ans;
    }
};
// @lc code=end

