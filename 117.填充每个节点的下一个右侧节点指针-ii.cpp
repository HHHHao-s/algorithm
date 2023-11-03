#include "s.h"
/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start

// Definition for a Node.



class Solution {


public:
    Node* connect(Node* root) {
        if(root==nullptr){
            return root;
        }
        root->next = nullptr;
        
        Node *next_floor=root;
        while(next_floor!=nullptr){
            Node*node = next_floor;
            next_floor=nullptr; 
            Node *last=nullptr;
            while(node){
                if(node->right && node->left){
                    if(last!=nullptr){
                        last->next = node->left;
                    }else{
                        next_floor = node->left;
                    }
                    node->left->next = node->right;
                    last = node->right;
                }
                else if(node->left && node->right==nullptr){
                    if(last!=nullptr){
                        last->next = node->left;
                    }else{
                        next_floor = node->left;
                    }
                    last = node->left;
                }else if(node->right && node->left==nullptr){
                    if(last!=nullptr){
                        last->next = node->right;
                    }
                    else{
                        next_floor = node->right;
                    }
                    last = node->right;
                }
                node=node->next;    
            }
            if(last){
                last->next = nullptr;
            }
        }
        return root;
        
        

    }
};
// @lc code=end

