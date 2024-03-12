#include "s.h"
/*
 * @lc app=leetcode.cn id=1862 lang=cpp
 *
 * [1862] 向下取整数对和
 */

// @lc code=start
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {

        int upper = 0;

        vector<int> cnt(100001);

        for(int num: nums){

            upper = max(num ,upper);
            cnt[num]++;

        }

        vector<long long> presum(100002);
        presum[0] = 0;
        for(int i=1;i<=100000;i++){
            presum[i] = presum[i-1] + cnt[i];
        }

        long long ans = 0;
        const long long MOD = 1e9+7;

        for(long long i=1;i<=upper;i++){
            if(cnt[i]){
                for(long long d=1;i*d<=upper;d++){
                    ans = (ans+cnt[i]*d* (presum[min((long long)upper, (d+1)*i - 1)]-presum[d*i-1]))%MOD;
                }
            }
        }
        ans = ans<0?ans+MOD: ans;
        return (int)ans;



    }
};
// @lc code=end

