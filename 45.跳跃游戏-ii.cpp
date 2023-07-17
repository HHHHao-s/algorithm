#include "s.h"
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    // int jump(vector<int>& nums) {

    //     int n = nums.size();

    //     vector<int> dp(n,100000);
    //     dp[0]= 0;
    //     for(int i=0;i<n;i++){
    //         for(int j=1;j<nums[i]+1;j++){
    //             if(i+j>n-1){
    //                 break;
    //             }
    //             dp[i+j] = min(dp[i]+1, dp[i+j]);
    //         }
    //     }

    //     return dp[n-1];

    // }

    int jump(vector<int>& nums) {

        int n = nums.size();

        int end = 0, max_pos = 0,step=0;

        for(int i=0;i<n-1;i++){
            max_pos = max(max_pos, nums[i]+i);
            if(i==end){
                end = max_pos;
                step++;
                if(end>=n-1){
                    break;
                }
            }

        }

        return step;

    }
    

};
// @lc code=end

