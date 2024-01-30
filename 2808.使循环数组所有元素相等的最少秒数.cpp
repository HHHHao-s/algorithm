#include "s.h"
/*
 * @lc app=leetcode.cn id=2808 lang=cpp
 *
 * [2808] 使循环数组所有元素相等的最少秒数
 */

// @lc code=start
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> numPos;

        int n = nums.size();
        for(int i=0;i<n;i++){
            numPos[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto [num ,poss]: numPos){
            int t=0;
            if(poss.size()==1){
                t = n/2;
            }else{
                poss.push_back(poss[0]+n);
                for(int j=1;j<poss.size();j++){
                    t = max(t,(poss[j]-poss[j-1])/2);
                }
                
                
            }
            ans = min(ans, t);

        }
        return ans;
    }
};
// @lc code=end

