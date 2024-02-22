#include "s.h"
/*
 * @lc app=leetcode.cn id=1483 lang=cpp
 *
 * [1483] 树节点的第 K 个祖先
 */

// @lc code=start
class TreeAncestor {
private:
    vector<vector<int>> ancestor;

public:
    TreeAncestor(int n, vector<int>& parent):ancestor(n, vector<int>(16, -1)) {

        for(int i=0;i<n;i++){
            ancestor[i][0] = parent[i];
        }

        for(int j = 1;j<16;j++){
            for(int i=1;i<n;i++){
                if(ancestor[i][j-1]!=-1){
                    ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
                }
            }
        }


    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<16;i++){
            if((k>>i)&1){
                node= ancestor[node][i];
                if(node==-1){
                    return -1;
                }
            }
        }

        return node;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end

