#include "s.h"
/*
 * @lc app=leetcode.cn id=3045 lang=cpp
 *
 * [3045] 统计前后缀下标对 II
 */

// @lc code=start
struct Node{
    unordered_map<int, Node*> sons;
    int count{0};
};


class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        
        long long ret =0;
        Node* t = new Node;

        for(const auto &word: words){
            
            Node *cur= t;

            int i=0,j=word.size()-1;
            for(;i<word.size();i++,j--){

                int pos = ((word[i]-'a')<<5) | (word[j]-'a');
                if(cur->sons[pos]==nullptr){
                    cur->sons[pos] = new Node;
                }
                cur=cur->sons[pos];
                ret += cur->count;

            }
            cur->count++;

        }
        
        
        return ret;

    }
};
// @lc code=end

