#include "s.h"
/*
 * @lc app=leetcode.cn id=2141 lang=cpp
 *
 * [2141] 同时运行 N 台电脑的最长时间
 */

// @lc code=start
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=0,r=accumulate(batteries.begin(), batteries.end(),0LL)/n;
        // sort(batteries.begin(), batteries.end());
        long long ans = -1;
        while(l<=r){
            long long time = (l+r)/2;
            long long full=0;
            long long sum=0;
            for(int battery: batteries){
                if(battery>=time){
                    full++;
                }else{
                    sum += (long long)battery;
                }
            }
            long long needToCharge = n-full;
            
            if(n<=full|| needToCharge*time<=sum  ){
                ans = time;
                l=time+1;
            }else{
                r= time -1;
            }


        }
        return ans;

    }
};
// @lc code=end

