#include "s.h"
/*
 * @lc app=leetcode.cn id=1203 lang=cpp
 *
 * [1203] 项目管理
 */

// @lc code=start
class Solution {
private:
    vector<int> topologicalSort(vector<vector<int>> &edge, vector<int> &in, int n){

        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int> ret;
        while(!q.empty()){
            int x = q.front();
            q.pop();

            ret.push_back(x);

            for(int adj: edge[x]){
                in[adj]--;
                if(in[adj]==0){
                    q.push(adj);
                }
            }
        }

        if(ret.size()==n){
            return ret;
        }else{
            return {};
        }

    }

public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // 1. 把没有组号的项目分配组
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i] = m++;
            }
        }

        // 2. 整理项目边集和组边集
        vector<vector<int>> group_edge(m);
        vector<vector<int>> item_edge(n);

        vector<int> group_in(m);
        vector<int> item_in(n);

        for(int i=0;i<n;i++){
            for(int before: beforeItems[i]){
                item_edge[before].push_back(i);
                item_in[i]++;
                if(group[before]!=group[i]){
                    group_edge[group[before]].push_back(group[i]);
                    group_in[group[i]]++;
                }
                
            }
        }

        // 3. 拓扑排序
        vector<int> group_sorted = topologicalSort(group_edge, group_in, m);
        if(group_sorted.empty()){
            return {};
        }
        vector<int> item_sorted = topologicalSort(item_edge, item_in, n);
        if(item_sorted.empty()){
            return {};
        }

        // 4. 从组映射到项目，组内项目按照拓扑排序结果排序
        unordered_map<int, vector<int>> group2items;

        for(int i=0;i<n;i++){
            group2items[group[item_sorted[i]]].push_back(item_sorted[i]);
        }

        vector<int> ret;

        for(int i=0;i<m;i++){
            for(int it: group2items[group_sorted[i]]){
                ret.push_back(it);
            }            
        }

        return ret;

    }
};
// @lc code=end

