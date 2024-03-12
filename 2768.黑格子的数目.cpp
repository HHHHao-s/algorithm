#include "s.h"
/*
 * @lc app=leetcode.cn id=2768 lang=cpp
 *
 * [2768] 黑格子的数目
 */

// @lc code=start
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        
        unordered_map<int ,unordered_map<int, int>> mp;

        vector<long long> ans(5);

        for(auto &c : coordinates){
            int x = c[0];
            int y = c[1];
            mp[x][y]++;
            if(x-1>=0)
                mp[x-1][y]++;
            if(y-1>=0)
                mp[x][y-1]++;
            if(x-1>=0 && y-1>=0)
                mp[x-1][y-1]++;
        }

        for(auto &[x, ys]: mp){
            for(auto [y,cnt] : ys){
                if(y<n-1 && x<m-1){
                    ans[cnt]++;
                }
            }
        }
        int sum = 0;
        for(int i=1;i<=4;i++){
            sum+= ans[i];
        }
        ans[0] = (long long)(m-1)*(n-1) - sum;
        return ans;

        


    }
};
// @lc code=end

