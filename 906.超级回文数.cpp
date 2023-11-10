#include "s.h"
/*
 * @lc app=leetcode.cn id=906 lang=cpp
 *
 * [906] 超级回文数
 */

// @lc code=start
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int res = 0;
        long l = stol(left);
        long r = stol(right);

        // 先判断偶数的情况 ABCCBA
        for (int i = 1; i < 100000; ++i)
        {
            string s = to_string(i);
            string s2 = s;
            reverse(s2.begin(), s2.end());
            long m= stol(s + s2);
            m *= m;
            // 超过范围提前结束遍历
            if (m > r)
            {
                break;
            }
            else if (m >= l && IsPalindrom(m))
            {
                ++res;
            }
        }

        // 再判断奇数的情况 ABCBA
        for (int i = 1; i < 100000; ++i)
        {
            string s = to_string(i);
            string s2 = s;
            reverse(s2.begin(), s2.end());
            long m= stol(s.append(s2.begin()+1, s2.end()));
            m *= m;
            // 超过范围提前结束遍历
            if (m > r)
            {
                break;
            }
            else if (m >= l && IsPalindrom(m))
            {
                ++res;
            }
        }

        return res;
    }

    bool IsPalindrom(long num)
    {
        long n = num;
        // 倒序的数字
        long revNum = 0;
        while (n > 0)
        {
            revNum = revNum * 10 + n % 10;
            n /= 10;
        }
        // 直接比较是否相等即可
        return revNum == num;
    }
};

// @lc code=end

int main(){
    Solution s;

    cout << s.superpalindromesInRange("4","1000");
}