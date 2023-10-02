#include "s.h"
/*
 * @lc app=leetcode.cn id=1774 lang=cpp
 *
 * [1774] 最接近目标价格的甜点成本
 */

// @lc code=start
class Solution {
public:
    int closestCost(const vector<int>& baseCosts,
        const vector<int>& toppingCosts,
        int target) {
            int n = toppingCosts.size();
            int base_n = baseCosts.size();
            unordered_set<int> baseCosts_set;
            for(int i=0;i<base_n;i++){
                baseCosts_set.insert(baseCosts[i]);
            }
            
            
            const int max_target = 20000;

            vector<vector<vector<bool>>> dp(3, vector<vector<bool>>(n+1, vector<bool>(max_target,false)));
            
            // dp[0][0][0]=true;
            
            for(int i=0;i<=n;i++){
                dp[0][i][0] = true;
                dp[1][i][0] = true;
                dp[2][i][0] = true;
            }
            for(int i=1;i<=2;i++){
                for(int j=1;j<=n;j++){
                    for(int k=1;k<=max_target+1;k++){
                        if(k-toppingCosts[j-1]>=0){
                            dp[i][j][k]=dp[i-1][n][k-toppingCosts[j-1]] || dp[i][j-1][k] || dp[i][j-1][k-toppingCosts[j-1]] || dp[i-1][n][k];
                        }else{
                            dp[i][j][k] = dp[i][j-1][k] || dp[i-1][n][k]; 
                        }
                        if(dp[i][j][k] && baseCosts_set.count(target-k)){
                            return target;
                        }
                    }
                }
            }
            
            // int ans =100000000000;
            int diff=100000000;
            
            int base_ret=10000000;
            for(int i=0;i<base_n;i++){
                int base = baseCosts[i];
                if(base>=target){
                    if(abs(diff)>base-target){
                        diff = base-target;
                        base_ret = base;
                    }
                    if(diff==0){
                        return target;
                    }
                }else{
                    if(abs(diff)>target-base){
                        diff = target-base;
                        base_ret = base;
                    }else if(diff>0 && diff == target-base){
                        diff = target-base;
                        base_ret = base;
                    }
                    if(diff==0){
                        return target;
                    }
                }
                
                
                for(int j=target-base;j>0;--j){
                    if(dp[2][n][j]){
                        if(abs(diff)>target-base-j){
                            diff = -(target-base-j);
                            base_ret = base;
                        }else if(diff>0 && diff==target-base-j){
                            diff = -(target-base-j);
                            base_ret = base;
                        }
                        break;
                    }

                }
                for(int j=target-base;j>=0&&j<=max_target+1;j++){
                    if(dp[2][n][j]){
                        if(abs(diff)>j-target+base){
                            diff =j-target+base;
                            base_ret = base;
                        }
                        break;
                    }
                }
                if(diff==0){
                    return target;
                }
                
                
            }

            if(target-base_ret+diff>=0 && dp[2][n][target-base_ret+diff]){
                return target+diff;
            }else{
                return base_ret;
            }
            


    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.closestCost(
        {3738,5646,197,7652},
        {5056},
        9853
    );

    return 0;
}