#include "s.h"
#include <deque>
/*
 * @lc app=leetcode.cn id=3835 lang=cpp
 *
 * [3835] 开销小于等于 K 的子数组数目
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> mx, mn;
        long long l=0,r=0;
        long long ret = 0;
        for(;r<nums.size();r++){
            long long num = nums[r];
            while(!mx.empty() && num>= nums[mx.back()] ){
                mx.pop_back();
            }
            mx.push_back(r);
            while(!mn.empty() && num <= nums[mn.back()]){
                mn.pop_back();
            }
            mn.push_back(r);
            long long cur = (nums[mx.front()]-nums[mn.front()])*(r-l+1);
            while(l<=r && cur > k){
                l++;
                if(mx.front()==l-1){
                    mx.pop_front();
                }
                if(mn.front()==l-1){
                    mn.pop_front();
                }
                cur = (nums[mx.front()]-nums[mn.front()])*(r-l+1);
            }
            ret += r-l+1;

        }
        return ret;
    }
};
// @lc code=end

