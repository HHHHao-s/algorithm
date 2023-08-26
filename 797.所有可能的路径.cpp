#include "s.h"
/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> ans;
    int n;
    

    void dfs(int x,const vector<vector<int>>& graph, vector<int> &carry){

        if(x==n-1){
            
            ans.emplace_back(carry);
            
        }

        for(auto i: graph[x]){
            carry.push_back(i);
            dfs(i, graph, carry);
            carry.pop_back();
        }


    }


    vector<vector<int>> allPathsSourceTarget(const vector<vector<int>>& graph) {

        n = graph.size();
        
        vector<int> carry;
        
        carry.reserve(n);
        carry.push_back(0);
        dfs(0,graph, carry);

        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;

    print2d(s.allPathsSourceTarget({
        {1,2},
        {3},
        {3},
        {}
    }));


    return 0;
}