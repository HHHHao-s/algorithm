#include "s.h"
/*
 * @lc app=leetcode.cn id=2680 lang=cpp
 *
 * [2680] 最大或值
 */

// @lc code=start
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        
        long long ret = 0;

        vector<long long > suf(nums.size()+1);
        for(int i=nums.size();i-->0;){

            suf[i] = suf[i+1] | nums[i];

        }
        long long pre = 0;
        for(int i=0;i<nums.size();i++){

            ret =  max(ret, pre | (1ll*nums[i] << k) | suf[i+1]);
            pre |= nums[i];

        }
        return ret;


    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> nums = {12,9};
    cout << s.maximumOr(nums, 1);

}