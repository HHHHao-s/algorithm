#include "s.h"
/*
 * @lc app=leetcode.cn id=2193 lang=cpp
 *
 * [2193] 得到回文串的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0, j = n - 1; i < j; i++) {
            for (int k = j; i != k; k--) if (s[i] == s[k]) {
                // 字母出现偶数次的情况，模拟交换
                for (; k < j; k++) swap(s[k], s[k + 1]), ans++;
                j--;
                goto OK;
            }
            // 字母出现奇数次的情况，计算它距离中间还有多少距离
            ans += n / 2 - i;
            OK: continue;
        }
        return ans;
    }
};

// @lc code=end

