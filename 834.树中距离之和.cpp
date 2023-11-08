#include "s.h"
/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 */

// @lc code=start
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        struct node_status
        {
            /* data */
            int index,son_nums, dist;
        };
        

        vector<vector<node_status>> grid(n);

        for(auto edge: edges){
            grid[edge[0]].push_back({edge[1],-1,-1});
            grid[edge[1]].push_back({edge[0],-1,-1});
        }


        function<pair<int,int>(int ,int)> dfs1=[&](int fa, int node)->pair<int,int>{    
            
            int th_cnt = 1;
            int th_dis = 0;

            for(auto &[next, num, dis]: grid[node]){
                if(next!=fa){
                    auto [ret_num, ret_dis] = dfs1(node, next);
                    num = ret_num;
                    dis = ret_dis;
                    th_cnt+=num;
                    th_dis+= dis+num;
                }
            }
            return {th_cnt, th_dis};

        };
        vector<int> ans(n);
        function<void(int ,int ,int ,int)> dfs2=[&](int fa, int node, int fa_cnt, int fa_dis){    
            
            int son_cnt=0;
            int son_dis=0;

            for(auto &[next, num, dis]: grid[node]){
                if(next!=fa){
                    son_cnt+=num;
                    son_dis+=dis+num;
                }
            }
            son_cnt+=fa_cnt;
            son_dis+=fa_cnt+fa_dis;
            ans[node]=son_dis;
            for(auto &[next, num, dis]: grid[node]){
                if(next!=fa){
                    dfs2(node, next, son_cnt-num+1, son_dis-dis-num);
                }
            }

            

        };
        dfs1(-1,0);
        dfs2(-1,0,0,0);
        return ans;

    }
};
// @lc code=end
int main(){
    Solution s;
    vector<vector<int>> g = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    printArr(s.sumOfDistancesInTree(6,g));
    vector<vector<int>> g = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    printArr(s.sumOfDistancesInTree(6,g));


}