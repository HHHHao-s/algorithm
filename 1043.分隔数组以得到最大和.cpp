#include "s.h"
/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */

// @lc code=start
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n+1);

        for(int i=0;i<n;i++){

            for(int j=i,mx=0;i-j<k&&j>=0;j--){
                mx = max(arr[j], mx);
                dp[i+1] = max(dp[i+1], dp[j]+(i-j+1)*mx);
            }

        }
        return dp[n];
    }
};
// @lc code=end

