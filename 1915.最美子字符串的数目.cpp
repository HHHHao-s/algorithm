#include "s.h"
/*
 * @lc app=leetcode.cn id=1915 lang=cpp
 *
 * [1915] 最美子字符串的数目
 */

// @lc code=start
class Solution {
public:
    long long wonderfulSubstrings(string word) {

        int n =word.size();
        // vector<int> pre(n);
        // pre[0] = 1<<(word[0]-'a');
        int pre = 0;
        vector<long long> cnt(1024);

        cnt[0] = 1;
        long long ans = 0;
        for(int i=0;i<n;i++){
            int cur = pre ^ (1<<(word[i]-'a'));
            ans += cnt[cur];
            for(int j=0;j<10;j++){
                ans += cnt[cur^(1<<j)];
            }
            pre=cur;
            cnt[cur]++;
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.wonderfulSubstrings("he");
}