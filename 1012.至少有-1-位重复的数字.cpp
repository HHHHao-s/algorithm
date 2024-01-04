#include "s.h"
/*
 * @lc app=leetcode.cn id=1012 lang=cpp
 *
 * [1012] 至少有 1 位重复的数字
 */

// @lc code=start
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s=  to_string(n);
        int m = s.size();

        vector<vector<int>> memo(m, vector<int>(1<<10, -1));


        function<int(int ,int ,int ,int) > f=[&](int i,int mask, int is_limit,int is_num){
            if(i==m){
                return is_num;
            }
            if(!is_limit && is_num && memo[i][mask]!=-1){
                return memo[i][mask];

            }
            int res=0;
            if(!is_num){
                res += f(i+1, mask, false, false);
            }
            
            int up = is_limit?s[i]-'0':9;
            for(int k=1-is_num;k<=up;k++){
                if((mask&(1<<k))==0){
                    res += f(i+1, mask | (1<<k), is_limit&&(k==up), true);
                }
            }
            if(!is_limit && is_num){
                memo[i][mask] = res;
            }
            return res;

            
        };

        return n-f(0,0,1,0);

    }
};
// @lc code=end

