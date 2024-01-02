#include "s.h"
/*
 * @lc app=leetcode.cn id=1542 lang=cpp
 *
 * [1542] 找出最长的超赞子字符串
 */

// @lc code=start
class Solution {
public:
    int longestAwesome(string s) {

        unordered_map<int,int> seq;
        int n = s.size();
        int cur = 0;
        int ans = 0;
        seq[0] = -1;
        // 状态压缩
        for(int i=0;i<n;i++){
            int digit = s[i]-'0';
            cur ^= (1<<digit);
            if(seq.count(cur)){
                ans = max(ans, i-seq[cur]);
            }else{
                seq[cur]=i;
            }

            for(int k=0;k<10;k++){
                int tmp = cur^(1<<k);
                if(seq.count(tmp)){
                    ans = max(ans, i-seq[tmp]);
                }
            }
        }
        return ans;

    }
};
// @lc code=end

