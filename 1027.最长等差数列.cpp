#include "s.h"
/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

// @lc code=start
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        auto [minit, maxit] = minmax_element(nums.begin(), nums.end());

        int range = *maxit - *minit;

        int ans = 0;
        for (int d = -range; d <= range; d++)
        {
            vector<int> dp(*maxit + 1, -1);
            for (int x : nums)
            {
                int pre = x - d;
                if (pre >= *minit && pre <= *maxit && dp[pre] != -1)
                {
                    dp[x] = max(dp[x], dp[pre] + 1);
                    ans = max(dp[x], ans);
                }
                dp[x] = max(dp[x], 1);
            }
        }

        return ans;
    }
};
// @lc code=end

int main()
{

    Solution s;
    vector<int> v = {9, 4, 7, 2, 10};
    cout << s.longestArithSeqLength(v);

    return 0;
}