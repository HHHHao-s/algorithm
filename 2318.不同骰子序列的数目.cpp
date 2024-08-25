#include "s.h"
/*
 * @lc app=leetcode.cn id=2318 lang=cpp
 *
 * [2318] 不同骰子序列的数目
 */

// @lc code=start
class Solution {
public:
    int distinctSequences(int n) {
        vector<unordered_set<int>> next = {
            {},
            {2,3,4,5,6},
            {1,3,5},
            {1,2,4,5},
            {1,3,5},
            {1,2,3,4,6},
            {1,5}
        };
        constexpr int MOD = 1e9+7;
        vector<vector<int> > dp(7, vector<int>(7,0));
        if(n==1){
            return 6;
        }else if(n==2){
            return 22;
        }
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                if(next[i].count(j)==1){
                    dp[i][j] = 1;
                }
                
            }
        }

        for(int i=3;i<=n;i++){
            vector<vector<int>> tmp(7, vector<int>(7,0));
            for(int j=1;j<=6;j++){
                for(int k=1;k<=6;k++){
                    for(int l=1;l<=6;l++){
                        if(j!=k && j!=l && next[k].count(l)==1){
                            if(next[l].count(j)==1){
                                tmp[l][j] = (dp[k][l] + tmp[l][j])%MOD;
                            }
                        }
                    }
                }
            }
            dp = move(tmp);
        }
        int ret= 0;
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                if(next[i].count(j)==1){
                    ret = (ret +  dp[i][j])%MOD;
                }
                
            }
        }
        if(ret < 0){
            ret += MOD;
        }
        return ret;
        




    }
};
// @lc code=end

