#include "s.h"
/*
 * @lc app=leetcode.cn id=2842 lang=cpp
 *
 * [2842] 统计一个字符串的 k 子序列美丽值最大的数目
 */

// @lc code=start
class Solution {
    const long long MOD = 1e9 + 7;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) res = res * x % MOD;
            x = x * x % MOD;
        }
        return res;
    }

    // 适用于 n 和 k 都比较小的场景（本题至多 26）
    long long comb(long long n, int k) {
        auto res = n;
        for (int i = 2; i <= k; i++)
            res = res * --n / i; // n,n-1,n-2,... 中的前 i 个数至少有一个因子 i
        return res % MOD;
    }

public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int cnt[26]{};
        for (char c: s)
            cnt[c - 'a']++;
        map<int, int> cc;
        for (int c: cnt)
            if (c) cc[-c]++; // -c 方便从大到小遍历

        long long ans = 1;
        for (auto [c, num]: cc) {
            if (num >= k)
                return ans * pow(-c, k) % MOD * comb(num, k) % MOD;
            ans = ans * pow(-c, num) % MOD;
            k -= num;
        }
        return 0; // k 太大，无法选 k 个不一样的字符
    }
};
// @lc code=end

