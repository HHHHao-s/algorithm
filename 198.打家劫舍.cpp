#include "s.h"
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    // int rob(const vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n,vector<int>(2,0));
    //     dp[0][0] = 0;
    //     dp[0][1] = nums[0];
    //     for(int i=1;i<n;i++){
    //         dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
    //         dp[i][1] = dp[i-1][0] + nums[i];
    //     }

    //     return max(dp[n-1][0], dp[n-1][1]);
    // }

    int rob(const vector<int>& nums) {
        
        int n = nums.size();
        if(n==1){
            return nums[0];
        }else if(n==2){
            return max(nums[0],nums[1]);
        }

        int a=0,b=nums[0];// a为不选，b为选

        for(int i=1; i<n; i++){
            int tmp = a+nums[i];
            a = max(a,b);
            b = tmp;         
        }

        return max(a,b);

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.rob({2,1,1,2});


    return 0;
}