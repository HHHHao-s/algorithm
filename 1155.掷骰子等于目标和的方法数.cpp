#include "s.h"
/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] 掷骰子等于目标和的方法数
 */

// @lc code=start
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target+1,0);
        
        for(int i=1;i<=k&&i<=target;i++){
            dp[i]=1;
        }
        const int div = 1000000007;
        if(n*k<target){
            return 0;
        }
        for(int i=1;i<n;i++){
            vector<int> new_dp(target+1);
            for(int j=1;j<=k;j++){
                for(int o=1;o<=target;o++){
                    if(dp[o]!=0 && o+j<=target){
                        new_dp[o+j] = (new_dp[o+j] + dp[o])%div;
                    }
                }
            }
            dp = new_dp;
        }
        return dp[target];
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.numRollsToTarget(30,30,500);

    return 0;
}