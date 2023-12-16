#include "s.h"
/*
 * @lc app=leetcode.cn id=2402 lang=cpp
 *
 * [2402] 会议室 III
 */

// @lc code=start
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        auto f=[&](const vector<int>& a, const vector<int>& b){
            return a[0]<b[0];
        };
        sort(meetings.begin(), meetings.end(), f);
        vector<int> cnt(n);
        priority_queue<int, vector<int>, greater<>> empty;
        priority_queue<pair<long ,int>, vector<pair<long,int>>, greater<>> taken;
        for(int i=0;i<n;i++){
            empty.push(i);
        }
        for(auto &m: meetings){
            int st = m[0];
            int end = m[1];
            while(!taken.empty() && st>=taken.top().first){
                empty.push(taken.top().second);
                taken.pop();
            }
            if(empty.empty()){
                auto [m, id] = taken.top();
                taken.pop();
                taken.push({m+end-st, id});
                cnt[id]++;

            }else{
                auto id = empty.top();
                empty.pop();
                taken.push({end, id});
                cnt[id]++;
            }
        }
        int index = 0;
        for(int i=1;i<n;i++){
            if(cnt[i]>cnt[index]){
                index = i;
            }
        }
        return index;

    }
};
// @lc code=end

