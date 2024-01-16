#include "s.h"
/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

// @lc code=start
class Solution {
public:
    int findIntegers(int n) {

        string s;
        while(n){
            s.push_back(n&1);
            n>>=1;

        }
        reverse(s.begin(), s.end());
        int m = s.size();
        vector<vector<int>> memo(33,vector<int>(2,-1));
        function<int(int, int, bool)> f = [&](int i, int last, bool is_limit) -> int {
            if (i == m)
                return 1;
            if (!is_limit && memo[i][last] != -1)
                return memo[i][last];
            int res = 0;
            
            int up = is_limit ? s[i] : 1; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
            for (int d =0; d <= up; ++d) // 枚举要填入的数字 d
                if(!(last&d)){
                    res += f(i+1, d, (d==up)&&is_limit);
                }
            if (!is_limit)
                memo[i][last] = res;
            return res;
        };
        return f(0,0,1);
    }
};
// @lc code=end

