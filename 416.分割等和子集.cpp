#include "s.h"
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(const vector<int>& nums) {

        int n= nums.size();
        if(n==1){
            return false;
        }
        int sum=0,max_num=0;
        for(int i=0;i<n;i++){
            int x = nums[i];
            sum+=x;
            max_num = max(max_num,x);
        }
        if(sum&1){
            return false;
        }
        int target = sum/2;
        if(max_num>target){
            return false;
        }

        
        // vector<vector<bool>> dp(n+1, vector<bool>(target+1,false));

        // for(int i=0;i<=n;i++){
        //     dp[i][0] = true;
        // }

        // for(int i=1;i<=n;i++){
        //     int x = nums[i-1];
        //     for(int j=1;j<=target;j++){
        //         if(j-x>=0){
        //             dp[i][j] = dp[i-1][j-x] | dp[i-1][j];
        //         }else{
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }
        // }

        // return dp[n][target];

        vector<bool> dp(target+1, false);

        dp[0] = true;

        for(int i = 0;i<n;i++){
            int x = nums[i];
            for(int j=target+1;j-->x;){
                dp[j] = dp[j-x] || dp[j];
            }
        }

        return dp[target];
    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.canPartition({1,5,11,5});

    return 0;
}