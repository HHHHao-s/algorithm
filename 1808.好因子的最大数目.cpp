#include "s.h"
/*
 * @lc app=leetcode.cn id=1808 lang=cpp
 *
 * [1808] 好因子的最大数目
 */

// @lc code=start
// 迭代实现快速幂
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors==1 || primeFactors==2){
            return 1;
        }
        if(primeFactors==3){
            return 2;
        }
        int ngroup3 = primeFactors/3;
        int last = primeFactors%3;
        int ngroup2 = 0;
        if(last == 1){
            ngroup3--;
            ngroup2=2;
        }else if(last==2){
            ngroup2=1;
        }
        
        constexpr long long MOD = 1e9+7;
        long long ret=power(3, ngroup3, MOD);
        for(int i=0;i<ngroup2;i++){
            ret = (ret*2ll)%MOD;
        }
        if(ret<0){
            ret+=MOD;
        }
        return ret;

    }
};
// @lc code=end

