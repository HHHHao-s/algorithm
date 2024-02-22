#include "s.h"
/*
 * @lc app=leetcode.cn id=2209 lang=cpp
 *
 * [2209] 用地毯覆盖后的最少白色砖块
 */

// @lc code=start
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        
        int m = floor.size();
        vector<int> dp(m);
        if(numCarpets*carpetLen>=m){
            return 0;
        }
        int ct= 0;
        for(int i=0;i<m;i++){
            ct+=floor[i]-'0';
            dp[i] = ct;
        }
        for(int i=1;i<=numCarpets;i++){
            vector<int> ndp = vector<int>(m);
            ndp[carpetLen * i - 1] = 0;
            for(int j=carpetLen*i;j<m;j++){
                
                ndp[j] = min(ndp[j-1]+floor[j]-'0', dp[j-carpetLen]);
                

            }
            dp = move(ndp);
        }

        return dp[m-1];

    }
};
// @lc code=end

