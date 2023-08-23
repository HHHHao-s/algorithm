#include "s.h"
/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 */

// @lc code=start
class Solution {
public:

    int countGoodStrings(int low, int high, int zero, int one) {

        vector<long long> dp(high+1);

        dp[0] = 1;

        for(int i=1;i<=high;i++){
            if(i-zero>=0){
                dp[i] =(dp[i] + dp[i-zero])%(1000000007);
            }
            if(i-one>=0){
                dp[i] = (dp[i] + dp[i-one])%(1000000007);
            }
        }

        long long sum=0;
        for(int i=low;i<=high;i++){
            sum+=dp[i];
        }

        return sum%(1000000007);
        
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.countGoodStrings(2,3,1,2);

    return 0;
}