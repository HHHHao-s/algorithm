#include "../s.h"

class Solution {
public:
    long long minIncrementOperations(vector<int>& a, int k) {
        int n = a.size();
        const long long INF = 1000000000000000000LL;
        // 选择这个数最小的ans
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= 3; ++j)
            {
                if (i - j >= 0)
                {
                    dp[i] = min(dp[i], dp[i - j] + max(k - a[i - 1], 0));
                }
            }
        }
        long long res = INF;
        for (int j = max(n - 2, 1); j <= n; ++j)
            res = min(res, dp[j]);
        return res;
    }
};

int main(){

    Solution s;
    vector<int>nums={13,34,0,13,9,19};

    cout << s.minIncrementOperations(nums,82);
}