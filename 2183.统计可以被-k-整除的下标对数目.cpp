#include "s.h"
/*
 * @lc app=leetcode.cn id=2183 lang=cpp
 *
 * [2183] 统计可以被 K 整除的下标对数目
 */

// @lc code=start
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        
        // 思路
        // 如果a*b能被k整除，那么gcd(a,k)*gcd(b,k)也能被k整除
        // gcd的意思是求取二者相关的因数，其他因数可以忽略
        // 例如，对两个数质因数分解，15=3*5，30= 2*3*5，gcd就是3*5，我们并不关心3*5外的数。
        // 无论如何，如果两个gcd相乘能被k整除，那么这两个数乘上无关gcd的数也能被整除

        unordered_map<int,int> freq;
        for(int num: nums){
            freq[gcd(num, k)]++;
        }
        long long ans = 0;
        for(auto [x, frex]: freq){
            for(auto [y, frey]: freq){
                if((((long long)x)*y)%k==0){
                    ans += ((long long)frex)*frey;
                }
            }
        }

        for(int num: nums){
            if((((long long)num)*num)%k==0){
                ans --;
            }
        }
        return ans/2;

    }
};
// @lc code=end

