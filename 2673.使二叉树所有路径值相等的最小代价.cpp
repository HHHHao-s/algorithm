#include "s.h"
/*
 * @lc app=leetcode.cn id=2673 lang=cpp
 *
 * [2673] 使二叉树所有路径值相等的最小代价
 */

// @lc code=start
class Solution {
private:
    int ans = 0;
    int dfs(int n,int index, vector<int>& cost){

        int left = index*2;
        int right = index*2+1;
        if(left>n||right>n){
            return cost[index-1];
        }
        int lcost = dfs(n, left, cost);
        int rcost = dfs(n, right, cost);
        if(lcost<rcost){
            swap(lcost, rcost);
        }
        ans += lcost-rcost;
        return lcost + cost[index-1];

    }

public:
    int minIncrements(int n, vector<int>& cost) {
        dfs(n ,1, cost);
        return ans;
    }
};
// @lc code=end

