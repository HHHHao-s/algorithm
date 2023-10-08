#include "s.h"
/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
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
    /*string getDirections(TreeNode* root, int startValue, int destValue) {
        queue<pair<TreeNode*, string>> q;

     
        q.push({root, ""});
        bool start=false;
        bool dest = false;
        int first=-1;
        string sstart="";
        string sdest = "";
        while(!q.empty()){

            auto node = q.front().first;
            string s = std::move(q.front().second);
            q.pop();
            if(node->val==startValue){
                start=true;
                sstart = s;

            }
            if(node->val==destValue){
                dest = true;
                sdest = s;

            }
            if(start&&dest){
                string ret;
                int n1 = sstart.size();
                int n2 = sdest.size();
                if(n1<n2){

                    
                    int i=0;
                    for(;i<n1;i++){
                        if(sstart[i]==sdest[i]){
                            continue;
                        }
                        break;
                    }
                    ret.reserve(n1+n2);

                    int tmp_i = i;
                    for(;i<n1;i++){
                        ret.push_back('U');
                    }
                    i = tmp_i;
                    for(;i<n2;i++){
                        ret.push_back(sdest[i]);
                    }
                }else{
                    
                    
                    int i=0;
                    for(;i<n2;i++){
                        if(sstart[i]==sdest[i]){
                            continue;
                        }
                        break;
                    }
                    ret.reserve(n1+n2);
                    
                    int tmp_i = i;
                    for(;i<n1;i++){
                        ret.push_back('U');
                    }
                    i = tmp_i;
                    for(;i<n2;i++){
                        ret.push_back(sdest[i]);
                    }
                }
                return ret;
            }

            if(node->left){
                q.push({node->left, s+'L'});
            }
            if(node->right){
                q.push({node->right, s+'R'});
            }

        }

        return "";
    }*/
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*> fa;   // 父节点哈希表
        TreeNode* s = nullptr;   // 起点节点
        TreeNode* t = nullptr;   // 终点节点
        
        // 深度优先搜索维护哈希表与起点终点
        function<void(TreeNode*)> dfs = [&](TreeNode* curr) {
            if (curr->val == startValue) {
                s = curr;
            }
            if (curr->val == destValue) {
                t = curr;
            }
            if (curr->left) {
                fa[curr->left] = curr;
                dfs(curr->left);
            }
            if (curr->right) {
                fa[curr->right] = curr;
                dfs(curr->right);
            }
        };
        
        dfs(root);
        
        // 求出根节点到对应节点的路径字符串
        function<string(TreeNode*)> path = [&](TreeNode* curr) {
            string res;
            while (curr != root) {
                TreeNode* par = fa[curr];
                if (curr == par->left) {
                    res.push_back('L');
                }
                else {
                    res.push_back('R');
                }
                curr = par;
            }
            reverse(res.begin(), res.end());
            return res;
        };
        
        string path1 = path(s);
        string path2 = path(t);
        // 计算最长公共前缀并删去对应部分，同时将 path_1 逐字符修改为 'U'
        int l1 = path1.size(), l2 = path2.size();
        int i = 0;
        while (i < min(l1, l2)) {
            if (path1[i] == path2[i]) {
                ++i;
            }
            else {
                break;
            }
        }
        string finalpath(l1 - i, 'U');   // 最短路径对应字符串 
        finalpath.append(path2.substr(i, l2 - i));
        return finalpath;
    }

    
};
// @lc code=end

