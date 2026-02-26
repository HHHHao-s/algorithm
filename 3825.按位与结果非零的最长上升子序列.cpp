class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        int w = bit_width((uint32_t) ranges::max(nums));
        for (int i = 0; i < w; i++) {
            // 300. 最长递增子序列
            vector<int> f;
            for (int x : nums) {
                if ((x >> i & 1) == 0) { // x 二进制的第 i 位是 0
                    continue;
                }
                auto it = ranges::lower_bound(f, x);
                if (it != f.end()) {
                    *it = x;
                } else {
                    f.push_back(x);
                }
            }
            ans = max(ans, (int) f.size());
        }
        return ans;
    }
};

