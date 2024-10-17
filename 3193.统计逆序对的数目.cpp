#include "s.h"
/*
 * @lc app=leetcode.cn id=3193 lang=cpp
 *
 * [3193] 统计逆序对的数目
 */

// @lc code=start
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int maxCnt=0;
        unordered_map<int, int> mp;
        for(auto &r: requirements){
            maxCnt = max(maxCnt, r[1]);
            mp[r[0]] = r[1];
        }
        if(mp[0]){
            return 0;
        }
        const int MOD = 1e9+7;
        vector<vector<int>> memo(n+1, vector<int>(maxCnt+1, -1));
        auto dfs=[&](auto &&dfs, int i,int j){

            if(i==0){
                return 1;
            }
            if(memo[i][j]!=-1){
                return memo[i][j];
            }
            int res = 0;
            
            if(mp.count(i-1)==0){
                for(int k=0;k<=min(i,j);k++){
                    res  = (res+dfs(dfs, i-1, j-k))%MOD;
                }
            }else{
                int r = mp[i-1];
                if(j>=r && j-i<=r){
                    res = dfs(dfs ,i-1, r)%MOD;
                }
            }

            memo[i][j] = res;
            return res;


        };

        return dfs(dfs, n-1, mp[n-1]);
        

    }
};
// @lc code=end

