#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <future>
#include <thread> // 包含sleep_for
#include <chrono> // 包含chrono_literals
#include <deque>
#include <time.h>
#include <random>
using namespace std;


  struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断二叉树是否为规整二叉树
     * @param root TreeNode类 二叉树根节点
     * @return string字符串
     */

    bool dfs(TreeNode* l ,TreeNode* r){

        if(l->val!=r->val){
            return false;
        }
        bool ret = 1;
        if(l->left==nullptr && l->right == nullptr && r->left==nullptr && r->right==nullptr){
            return true;
        }
        if((r->left &&( l->right==nullptr)) 
            || (r->right && (l->left==nullptr))
            || (l->left && (r->right==nullptr))
            || (l->right && (r->left == nullptr))){
            return false;
        }
        if(l->left && r->right){            
            if(! dfs(l->left, r->right)){
                return false;
            }  
            
        }
        if(l->right && r->left){
            if( !dfs(l->right, r->left)){
                return false;
            }
        }
        
        return true;


    }

    string is_symmetric_tree(TreeNode* root) {
        // write code here
        

        if(root->left==nullptr && root->right==nullptr){
            return "yes";
        }

        if(root->left && root->right){
            bool ret = dfs(root->left, root->right);
            if(ret){
                return "yes";
            }else{
                return "no";
            }
        }
        

        return "no";


    }
};


int main(){

    

}




