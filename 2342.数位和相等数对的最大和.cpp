#include "s.h"
/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 */

// @lc code=start
class Solution {
private:
    int calc(int num){
        int ret=0;
        while(num){
            ret += num%10;
            num/=10;
        }
        return ret;
    }

public:
    int maximumSum(vector<int>& nums) {
        
        unordered_map<int, int> cl_num;
        int ans=-1;
        for(int a:nums){
            int c = calc(a);
            if(cl_num.count(c)){
                ans = max(ans, a+cl_num[c] );
                cl_num[c] = max(a, cl_num[c]);
            }else{
                cl_num[c] = a;
            }
        }

        return ans;

    }
};
// @lc code=end

