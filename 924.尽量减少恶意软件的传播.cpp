#include "s.h"
/*
 * @lc app=leetcode.cn id=924 lang=cpp
 *
 * [924] 尽量减少恶意软件的传播
 */

// @lc code=start
class Solution {
private:
    unordered_set<int> vis;
    unordered_set<int> init_cnt;
    map<int,int> cnt_init;
    void bfs(const vector<vector<int>>& graph, int node){
        queue<int> q;
        int cnt = 1;

        q.push(node);
        vis.insert(node);
        int min_init = node;
        bool single = true;
        
        while (!q.empty())
        {
            int next = q.front();
            q.pop();
            
            for(int i=0;i<graph[next].size();i++){
                if(graph[next][i]==1 && !vis.count(i)){
                    q.push(i);
                    vis.insert(i);
                    cnt++;
                    if(init_cnt.count(i)==1){
                        min_init = min(min_init, i);
                        single = false;
                    }
                }
            }
            
        }
        if(!single){
            
            if(cnt_init.count(0)){
                cnt_init[0] = min(cnt_init[0], min_init);
            }else{
                cnt_init[0] = min_init;
            }
            
        }else{
            if(cnt_init.count(cnt)){
                cnt_init[cnt] = min(cnt_init[cnt], node);
            }else{
                cnt_init[cnt] = node;
            }
            
        }
        

    }   

public:
    int minMalwareSpread(const vector<vector<int>>& graph,const vector<int>& initial) {

        // 无向
        // 统计从initial开始有几个点

        // bfs
        for(auto it: initial){
            init_cnt.insert(it);
        }
        
        for(int i=0;i<initial.size();i++){
            if(!vis.count(initial[i])){
                bfs(graph, initial[i]);
            }
        } 

        return cnt_init.rbegin()->second;


    

    }
};
// @lc code=end

int main(){
    Solution s;

    cout <<s.minMalwareSpread({
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,1},
        {0,0,1,1}
    },{3,1});

    return 0;
}