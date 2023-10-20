#include "s.h"
/*
 * @lc app=leetcode.cn id=805 lang=cpp
 *
 * [805] 数组的均值分割
 */

// @lc code=start
class Solution {
public:
    bool splitArraySameAverage(const vector<int>& nums) {
        
        int n = nums.size();
        int m = n/2;
        vector<unordered_set<int>> dp(m+1);
        dp[0].insert(0);
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        for(auto num:nums){
            for(int i=m;i>=1;i--){
                for(auto x: dp[i-1]){
                    int new_x = x+num;
                    if(new_x*(n-i)==(sum-new_x)*i){
                        return true;
                    }
                    dp[i].insert(new_x);
                }
            }
        }
        
        return false;


    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.splitArraySameAverage({1,2,3,4,5,6,7,8});

}