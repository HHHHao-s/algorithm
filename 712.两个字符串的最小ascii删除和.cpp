#include "s.h"
/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[0][0] = 0;
        
        for(int i=1,sum=0;i<=m;i++){
            sum+=s1[i-1];
            dp[i][0] = sum;
        }
        for(int i=1,sum=0;i<=n;i++){
            sum+=s2[i-1];
            dp[0][i] = sum;
        }

        for(int i=1;i<=m;i++){
            char c1 = s1[i-1];
            for(int j=1;j<=n;j++){
                char c2 = s2[j-1];
                if(c1==c2){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min({dp[i-1][j]+c1, dp[i][j-1]+c2});
                }
            }
        }

        return dp[m][n];

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.minimumDeleteSum("", "");


    return 0;
}