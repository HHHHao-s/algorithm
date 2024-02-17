#include "s.h"  
/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr){
            return {};
        }

        queue<Node*> q;

        q.push(root);

        vector<vector<int>> ret;


        while(!q.empty()){

            vector<int> level;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                Node *p = q.front();
                q.pop();
                level.push_back(p->val);
                for(Node *next: p->children){
                    q.push(next);

                }
            }

            ret.emplace_back(move(level));
            

        }

        return ret;
        

    }
};
// @lc code=end

