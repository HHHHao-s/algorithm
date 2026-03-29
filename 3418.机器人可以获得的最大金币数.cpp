#include "s.h"
/*
 * @lc app=leetcode.cn id=3418 lang=cpp
 *
 * [3418] 机器人可以获得的最大金币数
 */

// @lc code=start
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int ret = 0;
        int m =coins.size(), n =coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3)));


        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                for(int k=0;k<3;k++){

                    if(coins[i][j]>=0){
                        if(i-1 < 0 && j - 1 < 0){
                            dp[i][j][k] = coins[i][j];
                        } else if(i-1 < 0){
                            dp[i][j][k] = coins[i][j] + dp[i][j-1][k]; 
                        } else if(j-1 < 0){
                            dp[i][j][k] = coins[i][j] + dp[i-1][j][k];
                        } else{
                            dp[i][j][k] = coins[i][j] + max(dp[i-1][j][k], dp[i][j-1][k]);
                        }
                    }else {
                        if(i-1 < 0 && j - 1 < 0){
                            if(k==2){
                                dp[i][j][k] = coins[i][j];
                            }
                            else{
                                dp[i][j][k] = max(dp[i][j][k+1], coins[i][j]);
                            }
                        } else if(i-1 < 0){
                            if (k==2)
                                dp[i][j][k] = coins[i][j] + dp[i][j-1][k]; 
                            else{
                                dp[i][j][k] = max(dp[i][j-1][k+1], dp[i][j-1][k] + coins[i][j]);
                            }
                        } else if(j-1 < 0){
                            if (k==2)
                                dp[i][j][k] = coins[i][j] + dp[i-1][j][k]; 
                            else{
                                dp[i][j][k] = max(dp[i-1][j][k+1], dp[i-1][j][k] + coins[i][j]);
                            }
                        } else{
                            if (k==2)
                                dp[i][j][k] = coins[i][j] + max(dp[i-1][j][k], dp[i][j-1][k]); 
                            else{
                                dp[i][j][k] = max(max(dp[i-1][j][k+1],dp[i][j-1][k+1]), max(dp[i-1][j][k], dp[i][j-1][k]) + coins[i][j]);
                            }
                        }
                    }

                }

            }

        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});

    }
};
// @lc code=end

