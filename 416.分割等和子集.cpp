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
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 == 1){
            return false;
        }

        int target = sum/2;
        vector<int> dp(target+1,0);
        dp[0] =1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                if(dp[i-nums[j]]==1){
                    dp[i] = 1;
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.canPartition({1,2,5});

    return 0;
}