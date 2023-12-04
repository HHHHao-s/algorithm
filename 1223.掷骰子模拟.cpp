#include "s.h"
/*
 * @lc app=leetcode.cn id=1223 lang=cpp
 *
 * [1223] 掷骰子模拟
 */

// @lc code=start
class Solution {
private:
    const int MOD = 100000007;
    int quickPOW(int x, int n){
        int ret = 1;
        while(n){
            if(n&1){
                ret = (ret*x)%MOD;
            }
            x=(x*x)%MOD;
            n>>=1;
        }
        return ret;
    }

public:
    int dieSimulator(int n,const vector<int>& rollMax) {
        vector<vector<int>> dp(7,vector<int>(n+1));
        

        
        dp[6][0] = 0;
        

        for(int i=1;i<=n;i++){
            
            int tmp2=0;
            for(int j=0;j<6;j++){
                int pos = max(0, i-rollMax[i]-1);
                int sub = ((dp[6][pos] - dp[j][pos])%MOD+MOD)%MOD;
                dp[j][i] = dp[6][i-1]-sub;

            }
            


            dp[6][i+1] = tmp2;

        }
        return dp[6][n];
        
    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.dieSimulator(5, {2,1,1,3,3,2});
}