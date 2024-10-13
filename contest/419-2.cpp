#include "../s.h"

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

    multiset<int > have;


    int dfs(TreeNode* root){
        int ret = 0;
        if(root->left==nullptr && root->right==nullptr){
            have.insert(1);
            return 1;
        }

        if(root->left && root->right){

            int lv = dfs(root->left), rv = dfs(root->right);

            if(lv>=1 && lv==rv){
                have.insert(lv+1);
                ret=lv+1;
            }
        }else{
            if(root->left){
                dfs(root->left);
            }
            if(root->right){
                dfs(root->right);
            }
        }
        

        return ret;

    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        
        dfs(root);

        if(have.size()<k){
            return -1;
        }

        for(auto it= have.rbegin();it!=have.rend();it++){
            k--;
            cout << * it << endl;
            if(k==0){
                return (1<<(*it)) -1;
            }
        }
        return -1;

        

    }
};