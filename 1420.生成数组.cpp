#include "s.h"
/*
 * @lc app=leetcode.cn id=1420 lang=cpp
 *
 * [1420] 生成数组
 */

// @lc code=start
class Solution {
private:
    int f[51][51][101];
    const int MOD = 1000000007;

public:
    int numOfArrays(int n, int m, int k) {
        if(k==0){
            return 0;
        }
        memset(f, 0, sizeof(f));
        for(int i=1;i<=m;i++){
            f[1][1][i]=1;
        }

        for(int i=2;i<=n;i++){
            for(int j=1;j<=i && j<=k;j++){
                for(int l=1;l<=m;l++){
                    f[i][j][l] = ((long long)f[i-1][j][l]*(long long)l)%(MOD);
                    for(int l0=1;l<l;l++){
                        f[i][j][l] = (f[i][j][l]+f[i-1][j-1][l0]) %MOD;
                    }
                }

            }
        }
        int ans = 0;
        for(int i=1;i<=m;i++){
            ans = (ans+f[n][k][i]) % MOD;
        }
        return ans;

    }
};
// @lc code=end

