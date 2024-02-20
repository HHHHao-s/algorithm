#include "s.h"
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start

class Solution
{
public:
    TreeNode *buildTree(const vector<int> &preorder,const vector<int> &inorder)
    {
        

        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        function<TreeNode*(int , int , int )> build =[&](int index, int l, int r){
            if(l==r){
                return new TreeNode(preorder[index]);
            }else if(l>r){
                TreeNode *ret = nullptr;
                return ret;
            }
            TreeNode *root = new TreeNode(preorder[index]);
            int mid = mp[root->val];
            root->left = build(index+1, l, mid-1);
            root->right = build(index+ mid-l+1, mid+1, r);
            return root;

        };

        return build(0,0,inorder.size()-1);

    }
};
// @lc code=end
int main()
{

    Solution sl;

    printTree(sl.buildTree({1,2}, {2,1}));

    return 0;
}
