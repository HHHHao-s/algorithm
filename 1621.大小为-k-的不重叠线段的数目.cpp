#include "s.h"
/*
 * @lc app=leetcode.cn id=1621 lang=cpp
 *
 * [1621] 大小为 K 的不重叠线段的数目
 */

// @lc code=start
class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp0(n, vector<int>(k+1)), dp1(n, vector<int>(k+1));

        dp1[0][0] =1;
        const int MOD = 1e9+7;
        for(int i=1;i<n;i++){
            for(int j=0;j<=k;j++){
                dp1[i][j] = (dp1[i-1][j] + dp0[i-1][j])%MOD;

                if(j>0){
                    dp0[i][j] = (dp0[i-1][j-1]+dp0[i][j])%MOD;
                    dp0[i][j] = (dp1[i-1][j-1]+dp0[i][j])%MOD;
                }
                dp0[i][j] = (dp0[i-1][j] + dp0[i][j])%MOD;
                
            }
        }
        return (dp0[n-1][k] + dp1[n-1][k])%MOD;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.numberOfSets(4,2);
}