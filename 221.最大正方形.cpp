#include "s.h"
/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));
        int ans=0;
        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i] - '0';
            ans = max(ans, dp[0][i]);
        }
        for(int i=0;i<m;i++){
            dp[i][0] = matrix[i][0] - '0';
            ans = max(ans, dp[i][0]);
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='0') continue;

                int lu = dp[i-1][j-1];
                int l = dp[i-1][j];
                int u = dp[i][j-1];

                int x = min(lu,min(l,u)) +1;
                ans = max(ans, x*x);
                dp[i][j] = x;
            }
        }

        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;

    // vector<vector<char>> matrix=
    // {
    //     {'1','0','1','0','0'}
    //     ,{'1','0','1','1','1'}
    //     ,{'1','1','1','1','1'}
    //     ,{'1','0','0','1','0'}
    // };
    vector<vector<char>> matrix=
    {
        {'1','1'},
        {'1','1'}
    };

    cout << s.maximalSquare(matrix);

    return 0;
}