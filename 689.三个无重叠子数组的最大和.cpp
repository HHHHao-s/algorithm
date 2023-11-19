#include "s.h"
/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */

// @lc code=start
class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> preSum(n + 1);
		for (int i = 0; i < n; ++i) {
			preSum[i + 1] = preSum[i] + nums[i];
		}
		vector<vector<int>> dp(n + 1, vector<int>(4));
		for (int i = n - k; i >= 0; --i) {
			for (int j = 1; j < 4; ++j) {
				dp[i][j] = max(dp[i + 1][j], dp[i + k][j - 1] + preSum[i + k] - preSum[i]);
			}
		}

		vector<int> ans(3);
		int i = 0, j = 3, idx = 0;
		while (j > 0) {
			if (dp[i][j] > dp[i + k][j - 1] + preSum[i + k] - preSum[i]) {
				++i;
			}
			else {
				ans[idx++] = i;
				i += k;
				--j;
			}
		}
		return ans;
	}
};
// @lc code=end

