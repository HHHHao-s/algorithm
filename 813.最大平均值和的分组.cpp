#include "s.h"
/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 */

// @lc code=start
class Solution {
public:
    double largestSumOfAverages(const vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<double>> dp(k+1,vector<double>(n+1));
        int sum = 0;
        for(int i=n;i-->0;){
            sum+= nums[i];
            dp[1][i] = 1.0*sum/(n-i);
        }
        for(int i = 2;i<=k;i++){
            for(int j=n-i;j>=0;j--){
                int sum = 0;
                for(int l=j;l<=n-i;l++){
                    sum += nums[l];
                    double cur = 1.0*sum/(l-j+1);
                    dp[i][j] = max({ cur+dp[i-1][l+1],dp[i][j]});
                    
                }
            }
        }
        return dp[k][0];
        
    }
};
// @lc code=end

int main(){
    Solution s;

    cout << s.largestSumOfAverages({4,1,7,5,6,2,3},4);

    return 0;
}