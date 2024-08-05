#include "s.h"
/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

// @lc code=start
class Solution {
public:
    int findIntegers(int n) {

        string s;
        while(n){
            s.push_back(n&1);
            n>>=1;

        }
        reverse(s.begin(), s.end());
        int m = s.size();
        vector<vector<int>> memo(33,vector<int>(2,-1));
        function<int(int,int,int)> f = [&](int i, int last, int is_limit){

            if(i==m){
                return 1;
            }
            if(!is_limit && memo[i][last]!=-1){
                return memo[i][last];
            }
            int up = is_limit ? s[i] : 1;
            int ret =0;
            for(int d=0;d<=up;d++){
                if(!(last&d)){
                    ret += f(i+1, d, (up==d) && is_limit);   
                }
            }
            if(!is_limit){
                memo[i][last] = ret;
            }


            return ret;
        };
        return f(0,0,1);

    }
};
// @lc code=end

