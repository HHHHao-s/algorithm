#include "s.h"
/*
 * @lc app=leetcode.cn id=1557 lang=cpp
 *
 * [1557] 可以到达所有点的最少点数目
 */

// @lc code=start
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<bool> in(n);

        for(auto edge: edges){
            int a = edge[0];
            int b = edge[1];
            in[b]=1;
        }
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(in[i]==0){
                ans.push_back(i);
            }
        }

        return ans;

        

    }
};
// @lc code=end

