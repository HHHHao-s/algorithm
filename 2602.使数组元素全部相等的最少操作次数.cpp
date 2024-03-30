#include "s.h"
/*
 * @lc app=leetcode.cn id=2602 lang=cpp
 *
 * [2602] 使数组元素全部相等的最少操作次数
 */

// @lc code=start
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> presum(nums.size()+2);
        for(int i=0;i<nums.size();i++){
            presum[i+1] = nums[i] + presum[i];
        }
        vector<long long>ret;
        for(int q: queries){

            long long lcnt = upper_bound(nums.begin(),nums.end(), q)-nums.begin();
            long long rcnt = nums.size()-lcnt;
            long long lsum = presum[lcnt];
            long long rsum = presum[nums.size()]-lsum;

            ret.push_back(lcnt*q-lsum +  rsum-rcnt*q);
            
            
        }
        return ret;
    }
};
// @lc code=end

