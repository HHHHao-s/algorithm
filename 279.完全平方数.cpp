#include "s.h"
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:

    bool isPerfect(int x){
        int s = (int)sqrt(float(x));
        return s*s==x;
    }

    int numSquares(int n) {
        
        if(n==1){
            return 1;
        }else if(n==2){
            return 2;
        }
        vector<int> dp(n+1,1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<n+1;i++){
            if(isPerfect(i)){
                dp[i] = 1;
            }else{
                int min_num = 10000000;
                for(int j=1;j*j<i-1;j++){
                    min_num = min(dp[j*j]+dp[i-j*j],min_num);
                }
                dp[i] = min_num;
            }
        }   
        return dp[n];
    }
};
// @lc code=end

int main(){
    
    Solution s;
    cout << s.numSquares(3);

    return 0;
}

