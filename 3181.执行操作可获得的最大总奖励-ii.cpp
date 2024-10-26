#include "s.h"
/*
 * @lc app=leetcode.cn id=3181 lang=cpp
 *
 * [3181] 执行操作可获得的最大总奖励 II
 */

// @lc code=start
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        
        sort(rewardValues.begin(), rewardValues.end());

        bitset<100000> f0, f1;
        
        f0[0] = 1;

        for(int i=0,j=0;i<rewardValues.size();i++){
            while(j<rewardValues[i]){

                f1[j]  =f0[j];
                j++;
            }
            f0 |= (f1 << rewardValues[i]);
        }
        int ans = 0;
        for(int i=0;i<100000;i++){
            if(f0[i]){
                ans = i;
            }
        }
        return ans;



    }
};
// @lc code=end

