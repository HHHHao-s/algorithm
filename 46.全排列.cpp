#include "s.h"
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<int>&cur, int first, vector<vector<int>>&ret, int n){
        if(first==n){
            ret.emplace_back(cur);
            return;
        }
        for(int i=first;i<n;i++){
            swap(cur[first], cur[i]);
            dfs(cur, first+1, ret,n);
            swap(cur[first], cur[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;

        dfs(nums,0,ret,nums.size());
        return ret;
    }
};
// @lc code=end

