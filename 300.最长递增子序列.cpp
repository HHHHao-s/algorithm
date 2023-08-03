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

        int n= nums.size();
        if(n==1){
            return 1;
        }
        vector<int> l;
        l.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(nums[i]>l.back()){
                l.push_back(nums[i]);
            }else{
                
                auto p = lower_bound(l.begin(),l.end(),nums[i]);
                *p = nums[i];
            }

        }
        return l.size();
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.lengthOfLIS({10,9,2,5,3,7,101,18});


    return 0;
}