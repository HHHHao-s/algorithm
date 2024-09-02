#include "s.h"
/*
 * @lc app=leetcode.cn id=1639 lang=cpp
 *
 * [1639] 通过给定词典构造目标字符串的方案数
 */

// @lc code=start
class Solution {
public:
        int numWays(vector<string>& words, string target) {
        const int MOD = (int)1e9 + 7;
        int n = words[0].size(),m = target.size(),f[n + 1][m + 1];
        memset(f,0,sizeof(f));
        for(int i = 0;i <= n;i++) f[i][0] = 1;
        int cnt[n][26];
        memset(cnt,0,sizeof(cnt));
        for(int i = 0;i < n; i++){
            for(string &word : words){
                cnt[i][word[i] - 'a']++;
            }
        }
        for(int i = 0;i < n; i++){
            for(int j = 0;j < m ;j++){
                f[i + 1][j + 1] = (int)(((long)cnt[i][target[j] - 'a'] * f[i][j] + f[i][j + 1]) % MOD);
            }
        }

        return f[n][m];
    }
};
// @lc code=end

