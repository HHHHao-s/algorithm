#include "s.h"
/*
 * @lc app=leetcode.cn id=1770 lang=cpp
 *
 * [1770] 执行乘法运算的最大分数
 */

// @lc code=start
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();

        vector<vector<int>> memo(m+1, vector<int>(m+1,-1));

        auto dfs = [&](auto&&dfs,  int l, int r){
            if(l+r >= m){
                return 0;
            }
            if(memo[l][r]!=-1){
                return memo[l][r];
            }
            int index= l+r;

            int ret = nums[l]*multipliers[index] + dfs(dfs, l+1, r);
            ret = max(ret, nums[n-r-1]*multipliers[index] + dfs(dfs, l, r+1));
            memo[l][r] = ret;

            return ret;
        };


        return dfs(dfs, 0, 0);

    }
};
// @lc code=end

int main(){
    Solution s;

    vector<int> nums= {1,2,3}, mul={3,2,1};

    cout<< s.maximumScore(nums, mul);
}