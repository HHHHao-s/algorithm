#include "s.h"
/*
 * @lc app=leetcode.cn id=1969 lang=cpp
 *
 * [1969] 数组元素的最小非零乘积
 */

// @lc code=start
class Solution {
public:
    long long fastPow(long long x, long long n, long long mod) {
        long long res = 1;
        for (; n != 0; n >>= 1) {
            if (n & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }
    
    int minNonZeroProduct(int p) {
        if (p == 1) {
            return 1;
        }
        long long mod = 1e9 + 7;
        long long x = fastPow(2, p, mod) - 1;
        long long y = (long long) 1 << (p - 1);
        return fastPow(x - 1, y - 1, mod) * x % mod;
    }
};

// @lc code=end

int main(){
    Solution s;
    cout << s.minNonZeroProduct(3);
}