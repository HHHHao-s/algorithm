#include "s.h"
/*
 * @lc app=leetcode.cn id=1425 lang=cpp
 *
 * [1425] 带限制的子序列和
 */

// @lc code=start
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        if(mx<=0){
            return mx;
        }

        deque<pair<int,int>> dq;
        int ret =0 ;
        dq.push_back({-1,0});
        for(int i=0;i<n;i++){

            while(!dq.empty() && i-dq.front().first>k){
                dq.pop_front();
            }

            int cur= dq.front().second+nums[i];
            if(cur>0){
                while(!dq.empty()  && dq.back().second<=cur ){
                    dq.pop_back();
                }
                dq.push_back({i, cur});
                ret = max(ret,cur);
            }else{
                dq.push_back({i, 0});
            }

        }
        return ret;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums= {10,2,-10,5,20};
    cout<< s.constrainedSubsetSum(nums, 2);
}