#include "s.h"
/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 */

// @lc code=start
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        vector<vector<int>> dp(minProfit+1, vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        const int MOD = 1e9+7;
        for(int k=0;k<profit.size();k++){
            int p = profit[k];
            int g = group[k];
            auto tmp = dp;
            if(g<=n){                    
                for(int i=0;i<=minProfit;i++){
                    for(int j=1;j<=n-g;j++){
                        if(i+p>=minProfit){
                            tmp[minProfit][j+g] = (tmp[minProfit][j+g]+dp[i][j])%MOD;
                        }else{
                            tmp[i+p][j+g] = (tmp[i+p][j+g]+dp[i][j])%MOD;
                        }
                        
                    }
                }
                if(p<=minProfit){              
                    tmp[p][g]++;             
                }else{   
                    tmp[minProfit][g]++;                   
                }             
            }
            
            dp = tmp;
            
        }
        int ans =0;
        for(auto x: dp[minProfit]){
            ans = (ans+x)%MOD;
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> group = {80,40}, profit={88,88};

    cout << s.profitableSchemes(64,0,group, profit);
}