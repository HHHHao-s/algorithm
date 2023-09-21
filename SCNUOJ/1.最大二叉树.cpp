#include "stdio.h"
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{

    int val;
    TreeNode *left{nullptr};
    TreeNode *right{nullptr};
    TreeNode(){

    }
    TreeNode(int x):val(x){

    }  
    void print(){
        if(left==nullptr && right!=nullptr){
            printf("%d null ", val);
            right->print();
        }else if(left!=nullptr && right==nullptr){
            printf("%d ", val);
            left->print();
            printf("null ");
        }else if(left==nullptr && right == nullptr){
            printf("%d ", val);
        }else{
            printf("%d ", val);
            left->print();
            right->print();
        }
    }
};


TreeNode * gen(vector<int>& arr, int l, int r){

    if(l>=r){
        return nullptr;
    }
    TreeNode * ret = new TreeNode();

    int max_num=-1;
    int max_index=-1;
    for(int i=l;i<r;i++){
        if(arr[i]>max_num){
            max_index = i;
            max_num = arr[i];
        }
    }

    ret->val = max_num;
    ret->left = gen(arr, l, max_index);
    ret->right = gen(arr, max_index+1, r);

    return ret;

}

int main(){

    int a;

    int max_index=0;
    int max_num=-1;
    vector<int> arr;
    while(scanf("%d", &a)!=EOF){
        arr.push_back(a);
    }

    TreeNode *root = gen(arr, 0, arr.size());
    root->print();
    


    return 0;
}