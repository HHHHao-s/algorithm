#include "s.h"
/*
 * @lc app=leetcode.cn id=2561 lang=cpp
 *
 * [2561] 重排水果
 */

// @lc code=start
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<int,int> cnt;
        int mn=INT_MAX;
        for(int i= 0;i<n;i++){
            cnt[basket1[i]]++;
            cnt[basket2[i]]--;

        }
        vector<int> a;
        
        for(auto [x,c]: cnt){
            c = abs(c);
            if(c%2==1){
                return -1;
            }
            mn = min(mn, x);
            for(c=c/2;c-->0;){
                // 交换c/2个数
                a.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        long long ans=0;
        mn*=2;
        for(int i=0;i<a.size()/2;i++){
            ans = ans + min(a[i], mn);
        }
        return ans;

    }
};
// @lc code=end

