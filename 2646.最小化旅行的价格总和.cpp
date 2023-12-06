#include "s.h"
/*
 * @lc app=leetcode.cn id=2646 lang=cpp
 *
 * [2646] 最小化旅行的价格总和
 */

// @lc code=start
class Solution {
private:
    vector<int> new_price; 
    vector<vector<int>> grid;
    bool dfs(int node, int dst, int far, vector<int>& price){

        if(node==dst){
            return true;
        }
        for(int i=0;i<grid[node].size();i++){
            int next = grid[node][i];
            if(next!=far){
                new_price[next]+=price[next];
                bool ret = dfs(next, dst, node, price);
                if(ret){
                    return true;
                }else{
                    new_price[next]-=price[next];
                }
            }
            
        }
        return false;

    }
    vector<pair<int,int>> memo;
    int getMin(int node ,int far, int can){
        if(can && memo[node].first!=-1){
            return memo[node].first;
        }else if(!can && memo[node].second!=-1){
            return memo[node].second;
        }
        
        int a=new_price[node],b=new_price[node]/2;
        for(int i=0;i<grid[node].size();i++){
            int next = grid[node][i];
            if(next!=far){
                if(can){
                    b+=getMin(next, node, 0);
                }
                a += getMin(next, node, 1);
            }
            
        }

        if(can){

            memo[node].first = min(a,b);
            return min(a,b);
        }else{
            memo[node].second = a;
            return a;
        }
        
        
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        grid.resize(n);
        memo=vector<pair<int,int>>(n, {-1,-1});

        new_price.resize(n);

        for(auto &edge:edges){
            grid[edge[0]].push_back(edge[1]);
            grid[edge[1]].push_back(edge[0]);
        }

        for(auto &trip: trips){
            new_price[trip[0]]+=price[trip[0]];
            dfs(trip[0], trip[1],-1, price);
        }

        return getMin(0, -1, 1);



    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> edges={
        {0,1},
        {1,2},
        {1,3}
    };
    vector<int> price={
        2,2,10,6
    };
    vector<vector<int>> trips={
        {0,3},
        {2,1},
        {2,3}
    };
    cout<< s.minimumTotalPrice(4, edges, price, trips);
}