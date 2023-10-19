#include "s.h"
/*
 * @lc app=leetcode.cn id=1726 lang=cpp
 *
 * [1726] 同积元组
 */

// @lc code=start
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int, int> mul_cnt;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mul_cnt[nums[i]*nums[j]]+=1;
            }
        }
        int ans=0;
        for(const auto &it: mul_cnt){
            if(it.second>=2){
                ans += it.second*(it.second-1)*4;

            }
        }
        return ans;

    }
};
// @lc code=end

