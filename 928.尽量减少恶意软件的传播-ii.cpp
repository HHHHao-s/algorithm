#include "s.h"
/*
 * @lc app=leetcode.cn id=928 lang=cpp
 *
 * [928] 尽量减少恶意软件的传播 II
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, int>par, par_cnt;
    
    unordered_set<int> vis;

    void bfs(int node,const  vector<vector<int>>& graph, int n){

        queue<int> q;
        q.push(node);
        vis.insert(node);
        par_cnt[node]=1;
        while(!q.empty()){

            int cur = q.front();
            q.pop();
            for(int i=0;i<n;i++){
                if(graph[cur][i]==1 && !vis.count(i)){
                    q.push(i);
                    vis.insert(i);
                    par[i] = node;
                    par_cnt[node]++;
                }
            }

        }
        

    }

public:
    int minMalwareSpread(const vector<vector<int>>& graph, vector<int>& initial) {

        sort(initial.begin(),initial.end());

        for(auto node :initial){
            if(!vis.count(node)){
                bfs(node, graph, graph.size());
            }else{

                par_cnt[par[node]]=0;
            }
            
        }
        
        int ans = par_cnt.begin()->first;
        int ans_cnt = par_cnt.begin()->second;

        for(auto [init, cnt]: par_cnt){
            if(cnt>ans_cnt){
                ans = init;
                ans_cnt = cnt;
            }else if(cnt==ans_cnt && init<ans){
                ans = init;
                ans_cnt = cnt;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> inital = {0,1,2};
    cout << s.minMalwareSpread({
        {1,1,0},
        {1,1,0},
        {0,0,1}
    },inital);
}