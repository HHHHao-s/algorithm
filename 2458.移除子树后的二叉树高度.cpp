#include "s.h"
/*
 * @lc app=leetcode.cn id=2458 lang=cpp
 *
 * [2458] 移除子树后的二叉树高度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        vector<int> memo(100001);      
        function<int(TreeNode*)> dfs0 = [&](TreeNode *node){
            if(node->left==nullptr && node->right==nullptr){
                memo[node->val] = 1;
                return 1;
            }
            
            int l=0,r=0;
            if(node->left)
                l = dfs0(node->left);
            if(node->right)
                r= dfs0(node->right);
            memo[node->val] = max(l, r)+1;
            return max(l, r)+1;
        };

        dfs0(root);
        unordered_map<int, vector<int>> mq;
        
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            mq[queries[i]].push_back(i);

        }
        function<void(TreeNode*,int, int)> dfs = [&](TreeNode *node,int len, int fa_mx){

            if(node==nullptr){
                return ;
            }
            int l = node->left? memo[node->left->val]:0;
            int r = node->right?memo[node->right->val]:0;



            if(node->left){
                if(mq.count(node->left->val)){
                    for(int index:mq[node->left->val] ){
                        ans[index] = max(fa_mx, len+r);
                    }
                    
                }
                    
                dfs(node->left, len+1, max(fa_mx, len+r));
            }
            if(node->right ){
                if(mq.count(node->right->val)){
                    for(int index:mq[node->right->val] ){
                        ans[index] = max(fa_mx, len+l);
                    }
                    
                }
                dfs(node->right, len+1, max(fa_mx, len+l));
            }
            

        };

        dfs(root, 0, 0);
        

        return ans;
        

    }
};
/*
class Solution {
public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        unordered_map<TreeNode*, int> height; // 每棵子树的高度
        function<int(TreeNode*)> get_height = [&](TreeNode *node) -> int {
            return node ? height[node] = 1 + max(get_height(node->left), get_height(node->right)) : 0;
        };
        get_height(root);

        int res[height.size() + 1]; // 每个节点的答案
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode *node, int depth, int rest_h) {
            if (node == nullptr) return;
            ++depth;
            res[node->val] = rest_h;
            dfs(node->left, depth, max(rest_h, depth + height[node->right]));
            dfs(node->right, depth, max(rest_h, depth + height[node->left]));
        };
        dfs(root, -1, 0);

        for (auto &q : queries) q = res[q];
        return queries;
    }
};
// 灵神写的
*/
// @lc code=end

int main(){
    Solution s;
    TreeNode *root = genTree({1,null,5,3,null,2,4});
    vector<int> q = {4};
    printArr(s.treeQueries(root, q));
}