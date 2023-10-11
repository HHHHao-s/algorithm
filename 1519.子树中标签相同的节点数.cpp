#include "s.h"/*
 * @lc app=leetcode.cn id=1519 lang=cpp
 *
 * [1519] 子树中标签相同的节点数
 */

// @lc code=start
class Solution {
private:
    vector<int> ret;
    vector<vector<int>> grid;
    unordered_set<int> vis;

    void dfs(int id, const string& labels, vector<int>& label_cnt ){

        vis.insert(id);
        label_cnt[labels[id]-'a']++;
        for(int i=0;i<grid[id].size();i++){
            if(!vis.count(grid[id][i])){
                vector<int> tmp(26,0);
                dfs(grid[id][i], labels, tmp);
                for(int j=0;j<26;j++){
                    label_cnt[j]+=tmp[j];
                }
            }
            
        }
        
        ret[id]=label_cnt[labels[id]-'a'];



    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ret = vector<int>(n,0);
        grid = vector<vector<int>>(n);

        for(int i=0;i<edges.size();i++){
            grid[edges[i][0]].push_back(edges[i][1]);
            grid[edges[i][1]].push_back(edges[i][0]);

        }

        vector<int> tmp(26,0);
        dfs(0, labels, tmp);
        return ret;

    }
};
// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> edges={
        {0,1},{0,2},{1,4},{1,5},{2,3},{2,6}
    };
    printArr(s.countSubTrees(7,edges, "abaedcd"));

    return 0;
}