#include "s.h"
/*
 * @lc app=leetcode.cn id=1569 lang=cpp
 *
 * [1569] 将子数组重新排序得到同一个二叉搜索树的方案数
 */

// @lc code=start
struct TNode
{
    int val{0};
    TNode *left{nullptr};
    TNode *right{nullptr};
    int ans{-1};
    int size{1};
    TNode(){}
    TNode(int x) : val(x) {}
    TNode(int x, TNode *left, TNode *right) : val(x), left(left), right(right) {}

    
};

void insert(TNode*p,  int x){
    while(1){
        if(p->val<x){
            if(p->left==nullptr){
                p->left = new TNode(x);
                break;
            }else{
                p=p->left;
            }
        }else{
            if(p->right==nullptr){
                p->right = new TNode(x);
                break;

            }else{
                p=p->right;
            }
        }
    }
    

}

class Solution {
private:
    const int MOD{1000000007};
    vector<vector<int>> c;
    void dfs(TNode *node){
        if(!node){
            return;
        }
        dfs(node->left);
        dfs(node->right);
        int lsize = node->left?node->left->size:0;
        int rsize = node->right?node->right->size:0;
        int lcnt = node->left?node->left->ans:1;
        int rcnt = node->right?node->right->ans:1;
        node->size = lsize+rsize+1;
        node->ans = (long long)c[lsize+rsize][lsize]%MOD*lcnt%MOD*rcnt%MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        c.assign(n+1, vector<int>(n+1));
        c[0][0]=1;
        for(int i=1;i<n;i++){
            c[i][0]  =1;
            for(int j=1;j<n;j++){
                c[i][j] = (c[i-1][j]+c[i-1][j-1])%MOD;
            }
        }
        TNode *head = new TNode(nums[0]);
        for(int i=1;i<n;i++){
            insert(head, nums[i]);
        }
        dfs(head);
        return (head->ans-1+MOD)%MOD;





    }
};
// @lc code=end

