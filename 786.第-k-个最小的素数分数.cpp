#include "s.h"
/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        auto f=[&](const pair<int,int>& a,const pair<int,int>&b){
            return arr[a.first]*arr[b.second]>arr[b.first]*arr[a.second];
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(f)> q(f);
        int n = arr.size();
        for(int i=1;i<n;i++){
            q.push({0, i});
        }

        for(int i=1;i<k;i++){
            auto [pos1, pos2] = q.top();
            q.pop();
            q.push({pos1+1, pos2});

        }
        auto [pos1, pos2] = q.top();
        return {arr[pos1], arr[pos2]};
        

    }
};
// @lc code=end

