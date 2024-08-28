#include "s.h"
/*
 * @lc app=leetcode.cn id=3144 lang=cpp
 *
 * [3144] 分割字符频率相等的最少子字符串
 */

// @lc code=start
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        int ret= INT_MAX;
        vector<vector<int>> memo(n+1,vector<int>(n+1, -1));
        auto dfs = [&](auto &&dfs, int l, int r){
            if(l==r){
                return 0;
            }
            if(memo[l][r]!=-1){
                return memo[l][r];
            }
            int ans= 2*n;
            int max_cnt = 0;
            unordered_map<int ,int> occ;
            for(int i=l;i<r;i++){
                int num = s[i]-'a';
                
                occ[num]++;
                max_cnt = max(max_cnt, occ[num]);
                if(max_cnt * occ.size() == i-l+1){
                    ans = min(ans, dfs(dfs, i+1, r)+1);
                }
            }
            
            memo[l][r] = ans;
            return ans;

        };

        return dfs(dfs, 0, n);

    }
};
// @lc code=end

