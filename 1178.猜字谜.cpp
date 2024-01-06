#include "s.h"
/*
 * @lc app=leetcode.cn id=1178 lang=cpp
 *
 * [1178] 猜字谜
 */

// @lc code=start

class Trie{
public:
    Trie() = delete;
    Trie(int range_):range(range_) ,sons(range_){

    }

    void insert(const string& str){
        Trie *cur = this;
        for(char c: str){
            if(cur->sons[c-'a']==nullptr){
                cur->sons[c-'a'] = new Trie(sons.size());
            }
            cur = cur->sons[c-'a'];

        }
        cur->count++;
        

    }

    int find(const string& str,int pos, char required ){
        if(pos>=7){
            return count;
        }
        Trie *next = sons[str[pos]-'a'];
        int ret = 0;
        if(next){
            ret += next->find(str, pos+1, required);
        }
        
        
        if(str[pos]!=required){
            ret+= find(str, pos+1, required);
        }
        return ret;


    }

    ~Trie(){
        for(auto t: sons){
            delete t;
        }
    }

private:
    int range{0};
    int count{0};
    vector<Trie*> sons;
};

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {

        Trie *root = new Trie(26);

        for(auto &word: words){
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()) ,word.end());
            root->insert(word);

        }
        vector<int > ans; 
        for(auto &puzzle: puzzles){
            char required = puzzle[0];
            sort(puzzle.begin(), puzzle.end());
            ans.push_back(root->find(puzzle, 0, required));
        }

        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<string> words={
        "aaaa","asas","able","ability","actt","actor","access"
    };
    vector<string> puzzles={
        "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"
    };
    printArr(s.findNumOfValidWords(words, puzzles));
}