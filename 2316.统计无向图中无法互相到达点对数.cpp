#include "s.h"
/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 *
 * [2316] 统计无向图中无法互相到达点对数
 */

// @lc code=start
class Solution {
private:
    vector<pair<int,int>> union_vec;

    int find(int x){
        return x==union_vec[x].first?x:(union_vec[x].first=find(union_vec[x].first));
    }
    void merge(int x, int y){
        int fa_x = find(x);
        int fa_y = find(y);
        if(fa_x!=fa_y){
            union_vec[fa_x].first = fa_y;
            union_vec[fa_y].second += union_vec[fa_x].second;
        }
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<bool> visited(n, false);
        union_vec = vector<pair<int,int>>(n);
        for(int i=0;i<n;i++){
            union_vec[i]={i,1};
        }

        vector<vector<int>> m(n);

        for(auto edge:edges){
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                queue<int> q;

                q.push(i);
                visited[i]=true;
                while(!q.empty()){

                    int node = q.front();
                    q.pop();
                    
                    for(int next_node: m[node]){
                        if(!visited[next_node]){
                            q.push(next_node);
                            merge(next_node, node);
                            visited[next_node]=true;
                        }
                    }

                }
            }
        }
        long long ans=0;
        long long sum=0;
        vector<long long> each_size;
        for(int i=0;i<n;i++){
            if(union_vec[i].first==i){
                sum+= union_vec[i].second;
                each_size.push_back(union_vec[i].second);
            }
        }
        
        for(int i=0;i<each_size.size();i++){
            sum-=each_size[i];
            ans += each_size[i]* sum;
        }

        return ans;


    }
};
// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> edges={
        {0,2},
        {0,5},
        {2,4},

        {1,6},
        {5,4}
    };
    cout << s.countPairs(7, edges);
    

    return 0;
}