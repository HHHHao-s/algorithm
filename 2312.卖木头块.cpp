#include "s.h"
/*
 * @lc app=leetcode.cn id=2312 lang=cpp
 *
 * [2312] 卖木头块
 */

// @lc code=start
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        
        vector<vector<long long>> p(m+1, vector<long long>(n+1, -1));
        for(auto &each: prices){
            p[each[0]][each[1]] = each[2];

        }

        int ans = 0;
        vector<vector<long long>> memo(m+1, vector<long long>(n+1, -1));

        function<long long(int, int)> f= [&](int x, int y){
            if(memo[x][y]!=-1){
                return memo[x][y];
            }
            long long tmp = 0;
            if(p[x][y]!=-1){
                tmp = p[x][y];
            }
            if(x>1 ){
                for(int i=1;i<x;i++){
                    tmp = max(tmp, f(i,y)+f(x-i,y));
                }
            }
            if(y > 1){
                for(int i=1;i<y;i++){
                    tmp = max(tmp, f(x,i)+f(x, y-i));
                }
            }
            memo[x][y] = tmp;
            return tmp;
        };

        return f(m, n);

    }
};
// @lc code=end

