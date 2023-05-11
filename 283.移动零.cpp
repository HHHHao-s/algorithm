#include "s.h"
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {


        
        int top=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                
                nums[top++] = nums[i];
            }
        }

        for(int i=top;i<n;i++){
            nums[i] = 0; 
        }

    }
};
// @lc code=end

