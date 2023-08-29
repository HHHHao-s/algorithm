#include "s.h"
/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

// @lc code=start
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> far;
    int dfs(TreeNode* node, TreeNode* target, TreeNode *from){

        
        if(node==nullptr){
            return 0;
        }
        far[node] = from;
        if(node == target){
            return 1;
        }
        
        int a = dfs(node->left, target, node);
        if(!a){
            a = dfs(node->right, target, node);
        }
        return a;

    }

    vector<int> ret;

    void bfs(TreeNode* target, int k){

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);

        int step=0;

        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                
                TreeNode *node = q.front();
                q.pop();
                if(k==step){
                    ret.push_back(node->val);
                    continue;
                }
                if(node->left!=nullptr && !vis.count(node->left)){
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right!=nullptr && !vis.count(node->right)){
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(far.count(node)&& far[node]!=nullptr && !vis.count(far[node])){
                    q.push(far[node]);
                    vis.insert(far[node]);
                }
            }
            step++;
        }
       

    }

public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        dfs(root, target, nullptr);

        bfs(target, k);

        return ret;



    }
};
// @lc code=end

int main(){

    

    return 0;
}