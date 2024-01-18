#include "s.h"
/*
 * @lc app=leetcode.cn id=2171 lang=cpp
 *
 * [2171] 拿出最少数目的魔法豆
 */

// @lc code=start
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        map<int,int> cnt;
        long long sum = 0;
        for(int bean: beans){
            cnt[bean]++;
            sum+=bean;
        }
        long long ans=LONG_LONG_MAX;
        int n = beans.size();
        long long erased=0;
        for(auto [bean,ct]: cnt){
            long long eraseBean = (long long)bean*ct;
            long long floor = sum-(long long)bean*n;

            ans = min(ans, erased+ floor);
            sum-=eraseBean;
            
            n-=ct;
            erased+=eraseBean;
        }
        return ans;
    }
};
// @lc code=end

