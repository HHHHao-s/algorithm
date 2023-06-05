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
    TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return nullptr;
        stack<TreeNode *> st;
        TreeNode *pre_head = new TreeNode();
        TreeNode *p = pre_head;
        int pre = 0, in = 0;

        while (pre < preorder.size() && in < inorder.size())
        {
            p->left = new TreeNode(preorder[pre++]);
            p = p->left;
            st.push(p);
            while (p->val == inorder[in] && pre<preorder.size())
            {
                while (in < inorder.size())
                {
                    TreeNode *top = st.top();
                    if (top->val != inorder[in])
                    {
                        p->right = new TreeNode(preorder[pre++]);
                        p = p->right;
                        st.push(p);
                        break;
                    }
                    else
                    {
                        p=top;
                        st.pop();
                        in++;
                        if (st.empty())
                        {

                            p->right = new TreeNode(preorder[pre++]);
                            p = p->right;
                            st.push(p);
                            break;
                        }
                    }
                }
            }
        }

        return pre_head->left;
    }
};
// @lc code=end
int main()
{

    Solution sl;

    printTree(sl.buildTree({3,1,2,4}, {1,2,3,4}));

    return 0;
}
