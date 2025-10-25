#include "s.h"
/*
 * @lc app=leetcode.cn id=2845 lang=cpp
 *
 * [2845] 统计趣味子数组的数目
 */

// @lc code=start
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        long long psum = 0;
    
        unordered_map<int,long long> fuck;

        fuck[0] = 1;
        long long ret=0;

        for(int i=0;i<nums.size();i++){

            int m = nums[i]%modulo;

            psum += psum+(m==k);

            ret +=  fuck[(psum+modulo-k)%modulo];

            fuck[psum%modulo]++;

        }

        return ret;
        


    }
};
// @lc code=end

