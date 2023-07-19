#include "s.h"
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:


    int lengthOfLIS(const vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,1);
        int max_length = 1;

        dp[0] = 1;


        for(int i=1;i<n;i++){
            int tmp = dp[i];
            int x = nums[i];
            for(int j=0;j<i;j++){               
                if(x>nums[j]){
                    tmp = dp[j]+1>tmp?dp[j]+1:tmp;
                }
            }
            dp[i] = tmp;
            max_length = tmp>max_length?tmp:max_length;
        }

        return max_length;

    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.lengthOfLIS({7,7,7,7,7,7,7,8,7});


    return 0;
}