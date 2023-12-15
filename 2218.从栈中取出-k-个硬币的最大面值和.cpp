#include "s.h"
/*
 * @lc app=leetcode.cn id=2218 lang=cpp
 *
 * [2218] 从栈中取出 K 个硬币的最大面值和
 */

// @lc code=start
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k+1);
        int sumN=0;
        for(auto &pile: piles){
            int n = pile.size();

            for(int i=1;i<n;i++){
                pile[i]+=pile[i-1];
            }
            sumN = min(sumN+n, k);

            for(int j=sumN; j;j--){
                for(int w=0;w<min(j, n);w++){
                    dp[j] = max(dp[j], dp[j-w-1]+pile[w]);
                }
            }
        }
        return dp[k];
        
    }
};
// @lc code=end

