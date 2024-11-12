#include "s.h"
/*
 * @lc app=leetcode.cn id=2858 lang=cpp
 *
 * [2858] 可以到达每一个节点的最少边反转次数
 */

// @lc code=start
class Solution {
private:

    vector<int> f1r;

    int f1(int node ,int fa){
        if(f1r[node]!=-1){
            return f1r[node];
        }
        int ret =0 ;
        for(auto &next: real[node]){
            if(next!=fa){

                ret+=f1(next, node);

            }
        }
        for(auto &next: back_real[node]){
            if(next!=fa){
                ret+=f1(next, node) + 1;
            }
        }
        f1r[node] = ret;


        // cout<<'f' << node << ' ' << ret << endl;
        return ret;
    
    }
    
    void f(int node, int fa, int rev){

        int all = f1(node, fa);
        for(auto &next: real[node]){
            if(next!=fa){
                f(next, node, rev+all-f1r[next]+1);
            }
        }
        for(auto &next: back_real[node]){
            if(next!=fa){
                f(next, node, rev+all-f1r[next]-1);
            }
        }

        // cout<< node << ' ' << all+rev << endl;

        ans[node] = all+rev;

    
    }

    
    vector<vector<int>> real, back_real;
    vector<int> ans;
public:


    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        ans.assign(n,0);
        real.assign(n,{});
        f1r.assign(n+1, -1);
        back_real = real;
        for(auto &edge : edges){
            real[edge[0]].push_back(edge[1]);
            back_real[edge[1]].push_back(edge[0]);
        }

        f(0, -1, 0);
        return ans;

    }
};
// @lc code=end

int main(){
    vector<vector<int>> edges={
        {1,2},
        {2,0},
        
    };

    printArr( Solution().minEdgeReversals(3,edges));
}