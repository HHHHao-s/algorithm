#include    "s.h"
/*
 * @lc app=leetcode.cn id=1751 lang=cpp
 *
 * [1751] 最多可以参加的会议数目 II
 */

// @lc code=start
class Solution {
public:
    int maxValue(vector<vector<int>> &events, int k) {
        sort(events.begin(), events.end(), [](auto &a, auto &b) { return a[1] < b[1]; }); // 按照结束时间排序
        int n = events.size(), f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            int p = lower_bound(events.begin(), events.begin() + i, events[i][0],
                                [](auto &e, int lower) { return e[1] < lower; }) - events.begin();
            for (int j = 1; j <= k; ++j)
                // 为什么是 p 不是 p+1：上面算的是 >= events[i][0]，-1 后得到 < events[i][0]，但由于还要 +1，抵消了
                f[i + 1][j] = max(f[i][j], f[p][j - 1] + events[i][2]);
        }
        return f[n][k];
    }
};

// @lc code=end

int main(){
    Solution s;

    vector<vector<int>> evs={{19,42,7},{41,73,15},{52,73,84},{84,92,96},{6,64,50},{12,56,27},{22,74,44},{38,85,61}};

    cout << s.maxValue(evs, 5);
}