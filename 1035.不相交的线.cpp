#include "s.h"
/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1));

        

        for(int i=1;i<=m;i++){
            int num1 = nums1[i-1];
            for(int j=1;j<=n;j++){
                int num2 = nums2[j-1];
                if(num1 == num2){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];

    }
};
// @lc code=end

int main(){

    Solution s;

    vector<int> nums1={1,3,7,1,7,5};
    vector<int> nums2={1,9,2,5,1};

    cout << s.maxUncrossedLines(nums1, nums2);

    return 0;
}