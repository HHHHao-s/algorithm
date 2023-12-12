#include "s.h"
/*
 * @lc app=leetcode.cn id=2454 lang=cpp
 *
 * [2454] 下一个更大元素 IV
 */

// @lc code=start
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        
        stack<int> st1, st2, transfer;
        for (int i = 0; i < nums.size(); ++i) {
            while(!st1.empty() && nums[i]>nums[st1.top()]){
                res[st1.top()] = i;
                st1.pop();
            }
            while(!st2.empty() && nums[i]>nums[st2.top()]){
                transfer.push(st2.top());
                st2.pop();

            }
            while(!transfer.empty()){
                st1.push(transfer.top());
                transfer.pop();
            }
            st2.push(i);
        }
        return res;
    }
};

// @lc code=end

