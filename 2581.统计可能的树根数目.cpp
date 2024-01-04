#include "s.h"
/*
 * @lc app=leetcode.cn id=2581 lang=cpp
 *
 * [2581] 统计可能的树根数目
 */

// @lc code=start
class Solution {
private:

    vector<vector<int>> grid;
    unordered_map<int, unordered_set<int>> guess;
    int ans = 0;
    int k;

    unordered_map<int, int> memo;

    int dfs(int node, int forward, int far){
        if(forward==-1 && memo.count(node)){
            return memo[node];
        }
        int bw=0;
        int ret = 0;
        vector<int> bws(grid[node].size());
        for(int i=0;i<grid[node].size();i++){
            int next = grid[node][i];
            if(next!=far){  
                
                bws[i] = dfs(next, -1 ,node);
                memo[next] = bws[i];
                if(guess[next].count(node)){
                    bws[i]++;
                }
                bw+=bws[i];
                
            }
        }
        

        if(forward==-1){
            return bw;
        }else{
            for(int i=0;i<grid[node].size();i++){
                int next = grid[node][i];
                if(next!=far){  
                    if(guess[node].count(next)){
                        dfs(next, forward+bw-bws[i]+1 ,node);
                    }else{
                        dfs(next, forward+bw-bws[i], node);
                    }
                                  
                }
            }
            if(bw+forward>=k){
                ans++;
            }
        }
        
        return -1;

    }

public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int _k) {
        grid.resize(edges.size()+1);
        for(auto &edge : edges){
            grid[edge[0]].push_back(edge[1]);
            grid[edge[1]].push_back(edge[0]);
        }
        for(auto &gues: guesses){
            guess[gues[1]].insert(gues[0]);
        }
        k=_k;
        dfs(0, 0, -1);
        return ans;

    }
};
// @lc code=end


int main(){
    Solution s;
    vector<vector<int>> edges={
        {0,1},
        {1,2},
        {1,3},
        {4,2}
    };
    vector<vector<int>> guesses={
        {1,3},
        {0,1},
        {1,0},
        {2,4}
    };
    cout<< s.rootCount(edges, guesses, 3);
}