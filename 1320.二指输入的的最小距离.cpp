#include "s.h"
/*
 * @lc app=leetcode.cn id=1320 lang=cpp
 *
 * [1320] 二指输入的的最小距离
 */

// @lc code=start
class Solution {
public:
    int minimumDistance(string word) {


        vector<vector<int>> dis(27, vector<int>(27));

        for(int i=0;i<=26;i++){
            for(int j=0;j<=26;j++){
                dis[i][j] = abs(i%6 - j%6) + abs(i/6 - j/6);
            }
        }
        int n = word.size();
        
        int dp[n][26][26];

        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    dp[i][j][k] = INT_MAX;
                }
            }
        }

        for(int i=0;i<26;i++){
            dp[0][i][word[0]-'A'] = dp[0][word[0]-'A'][i] = 0;
        }


        for(int i=1;i<n;i++){
            char cur = word[i] -'A';
            char prev = word[i-1] -'A';
            int d = dis[prev][cur];
            for(int j=0;j<26;j++){
                // 左手在word[i-1]左手移动到word[i]
                dp[i][cur][j] = min(dp[i][cur][j] , dp[i-1][prev][j] +d);
                dp[i][j][cur] = min(dp[i][j][cur], dp[i-1][j][prev]+d);

            }
            for(int j=0;j<26;j++){
                // 右手在word[i-1]左手移动到word[i]
                dp[i][cur][prev] = min(dp[i][cur][prev], dp[i-1][j][prev] + dis[j][cur]);
                dp[i][prev][cur] = min(dp[i][prev][cur], dp[i-1][prev][j] + dis[j][cur]);
            }


        }

        int ans = INT_MAX >> 1;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = min(ans, dp[n - 1][i][j]);
            }
        }
        return ans;


    }
};
// @lc code=end

