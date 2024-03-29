#include "s.h"
/*
 * @lc app=leetcode.cn id=1691 lang=cpp
 *
 * [1691] 堆叠长方体的最大高度
 */

// @lc code=start
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        for(auto &cuboid:cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        auto f = [](const vector<int> & a,const vector<int> & b) {
            return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
        };

        sort(cuboids.begin(), cuboids.end(), f);

        vector<int> dp(cuboids.size());
        int ans= 0;
        for(int i=0;i<cuboids.size();i++){
            dp[i] = cuboids[i][2];
            for(int j=0;j<i;j++){
                if(cuboids[i][0]>=cuboids[j][0]&&
                cuboids[i][1]>=cuboids[j][1]&&
                cuboids[i][2]>=cuboids[j][2]){
                    dp[i] = max(dp[i], dp[j]+cuboids[i][2]);
                }
            }
            ans = max(ans, dp[i]);
            
        }
        return ans;

        

    }
};
// @lc code=end

