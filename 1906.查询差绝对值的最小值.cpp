#include "s.h"
/*
 * @lc app=leetcode.cn id=1906 lang=cpp
 *
 * [1906] 查询差绝对值的最小值
 */

// @lc code=start
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> presum(n+1 ,vector<int>(101, 0));
        for(int i=0;i<n;i++){
            for(int j=1;j<=100;j++){
                presum[i+1][j] = presum[i][j];
            }
            presum[i+1][nums[i]]++;
        }
        vector<int> ret;
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            int last = -1, best = INT_MAX;
            for(int i=1;i<=100;i++){
                int cnt = presum[r+1][i] - presum[l][i];
                if(cnt){
                    if(last!=-1){
                        best = min(i-last, best);
                        
                    }
                    last = i;
                }
            }
            if(best!=INT_MAX){
                ret.push_back(best);
            }else{
                ret.push_back(-1);
            }
        }

        return ret;

    }
};
// @lc code=end

