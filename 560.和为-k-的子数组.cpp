#include "s.h"
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        if(n==0){
            return 0;
        }
    
        unordered_map<int,int> m;
        m.insert({0,1});
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(m.find(sum-k)!=m.end()){
                ans+=m[sum-k];
            }
            m[sum]++;
        }
        return ans;



    }
};
// @lc code=end

