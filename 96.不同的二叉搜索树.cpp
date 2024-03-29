#include "s.h"
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        int sum = 1;

        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i] += dp[j]*dp[i-j-1];
            }

        }


        return dp[n];
    }
};
// @lc code=end

int main(){
    Solution s;

    cout << s.numTrees(3);

    return 0;
}