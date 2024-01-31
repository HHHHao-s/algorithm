#include "s.h"
/*
 * @lc app=leetcode.cn id=2306 lang=cpp
 *
 * [2306] 公司命名
 */

// @lc code=start
class Solution {
public:
    long long distinctNames(vector<string> &ideas) {
        unordered_map<string, int> group;
        for (auto &s : ideas)
            group[s.substr(1)] |= 1 << (s[0] - 'a');
        long ans = 0L;
        int cnt[26][26] = {};
        // 滚动dp
        for (auto &[_, mask] : group)
            for (int i = 0; i < 26; i++)
                if ((mask >> i & 1) == 0) {
                    for (int j = 0; j < 26; j++)
                        if (mask >> j & 1) ++cnt[i][j];
                } else {
                    for (int j = 0; j < 26; j++)
                        // 加上之前的符合条件的方案
                        if ((mask >> j & 1) == 0) ans += cnt[i][j];
                }
        return ans * 2;
    }
};


// @lc code=end

int main(){
    Solution s;
    vector<string> a = {"aaa","baa","caa","bbb","cbb","dbb"};
    cout<<s.distinctNames(a);
}