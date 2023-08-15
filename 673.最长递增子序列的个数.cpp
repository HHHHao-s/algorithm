#include "s.h"
/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp, cnt;

        for(auto x: nums){
            int pos, c=1;

            if(dp.size()==0||x>dp.back().back()){
                pos = dp.size();
            }else{
                pos = lower_bound(dp.begin(), dp.end(), x, 
                    [](const vector<int> &each_dp,const int& val)->bool{
                        return each_dp.back() < val;
                    }
                )-dp.begin();
            }

            if(pos>0){
                int pre = pos-1;
                int p2 = upper_bound(dp[pre].begin(), dp[pre].end(), x,greater<int>())-dp[pre].begin();
                c = cnt[pre].back() - (p2? cnt[pre][p2-1] : 0);
                
            }

            if(pos==dp.size()){
                dp.push_back({x});
                cnt.push_back({c});
            }else{
                dp[pos].push_back(x);
                cnt[pos].push_back(cnt[pos].back()+c);
            }


        }

        return cnt.size()? cnt.back().back():0;
    }
};
// @lc code=end

