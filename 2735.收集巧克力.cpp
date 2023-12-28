#include "s.h"
/*
 * @lc app=leetcode.cn id=2735 lang=cpp
 *
 * [2735] 收集巧克力
 */

// @lc code=start
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(n+1));
        long long sum=0;
        for(int i=0;i<n;i++){
            dp[0][i] = nums[i];
            sum+=dp[0][i];
        }
        dp[0][n] = sum;
    
        for(int i=1;i<=n;i++){
            long long sum = 0;
            for(int j=0;j<n;j++){
                
                dp[i][j] = min(dp[i-1][j],(long long) nums[(j-i+n)%n]);
                sum+=dp[i][j];
            }
            dp[i][n] = sum;
        }
        long long ans=LONG_LONG_MAX;
        for(int i=0;i<=n;i++){
            ans = min(ans, dp[i][n]+(long long)x*i);
        }
        return ans;

    }

};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {20,1,15};
    cout << s.minCost(nums, 5);
}