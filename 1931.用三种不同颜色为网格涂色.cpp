#include "s.h"
/*
 * @lc app=leetcode.cn id=1931 lang=cpp
 *
 * [1931] 用三种不同颜色为网格涂色
 */

// @lc code=start
class Solution {
public:
    int colorTheGrid(int m, int n) {

        vector<int> mask;
        for(int i=0;i<pow(3,m);i++){

            int last = -1;
            int cur = i;
            int can = 1;
            for(int j=0;j<m;j++){
                int t = cur%3;
                
                if(t == last){
                    can = 0;
                    break;
                }
                last =t ;
                
                cur/=3;
            }
            if(can){
                mask.push_back(i);
            }
        }
        vector<vector<long long>> dp(n, vector<long long>( pow(3,m)));

        for(int m1: mask){
            dp[0][m1] = 1;
        }
        const long long MOD = 1e9+7;
        for(int i=1;i<n;i++){

            for(int m1:mask){
                for(int m2:mask){
                    int t1=m1, t2=m2;
                    int can = 1;
                    for(int j=0;j<m;j++){
                        if(t1 % 3 == t2 % 3){
                            can = 0;
                            break;
                        }
                        t1/=3;
                        t2/=3;
                    }
                    if(can){
                        dp[i][m2] = (dp[i-1][m1]+dp[i][m2])%MOD;
                    }
                }
            }

        }
        long long ret = 0 ;
        for(int m1: mask){
            ret = (dp[n-1][m1] + ret)%MOD;
        }        
        if(ret<0){
            ret+=MOD;
        }
        return (int)ret;

    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.colorTheGrid(1,2);
}