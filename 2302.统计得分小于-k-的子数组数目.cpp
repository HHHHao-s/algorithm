#include "s.h"
/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int l=-1;
        int r=0;
        int n = nums.size();
        long long ans=0;
        long long sum = 0;
        while(r<n){
            sum+=nums[r];
            if(sum*(r-l)<k){
                ans+=r-l;
                r++;
            }else{
                do{
                    l++;
                    sum-=nums[l];
                }while(sum*(r-l)>=k);
                ans+=r-l;
                r++;
            }

        }

        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;

    vector<int> nums={
        2,1,4,3,5
    };
    cout << s.countSubarrays(nums, 10);


    return 0;
}