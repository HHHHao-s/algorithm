#include "s.h"
/*
 * @lc app=leetcode.cn id=1187 lang=cpp
 *
 * [1187] 使数组严格递增
 */

// @lc code=start
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
      
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        int n1 =arr1.size(), n2=arr2.size();
        vector<vector<int>> dp(n1+1, vector<int>(min(n2,n1)+1, INT_MAX));
        dp[0][0] = -1;

        for(int i=1;i<=n1;i++){
            int cur = arr1[i-1];
            for(int j=0;j<=min(i, n2);j++){
                if(cur>dp[i-1][j]){
                    dp[i][j] = cur;
                }
                if(j>0 && dp[i-1][j-1] != INT_MAX){
                    auto it = upper_bound(arr2.begin() + j - 1, arr2.end(), dp[i - 1][j - 1]);
                    if (it != arr2.end()) {
                        dp[i][j] = min(dp[i][j], *it);
                    }
                }
                if(i==n1 && dp[i][j] != INT_MAX){
                    return j;
                }

            }
            
        }
        return -1;
        



    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> a1 ={1,5,3,6,7}, a2={1,3,2,4};
    cout<< s.makeArrayIncreasing(a1, a2);
}