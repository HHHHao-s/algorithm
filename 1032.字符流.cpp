#include "s.h"
/*
 * @lc app=leetcode.cn id=1032 lang=cpp
 *
 * [1032] 字符流
 */

// @lc code=start
class StreamChecker {
private:
    vector<vector<int>> nexts;// 对每个word的next数组
    vector<int> p;// 对每个word的指针
    int wordn;
    vector<string> words;



public:

    StreamChecker(vector<string>& words) {
        wordn = words.size();
        p= vector<int>(wordn);
        nexts.resize(wordn);
        for(int k=0;k<wordn;k++){
            
            const string &pattern = words[k];
            int n = pattern.size();

            auto &next = nexts[k];


            next.push_back(0);
            int i = 1, j = 0;
            for (; i < pattern.length(); i++)
            {
                while (j > 0 && pattern[j] != pattern[i])
                { 
                    j = next[j - 1];
                }
                if (pattern[i] == pattern[j])
                {
                    j++; 
                }
                next.push_back(j);
            }

            

        }
        this->words = std::move(words);
    }
    

    bool query(char letter) {
        bool ret = false;
        for(int i =0;i<wordn;i++){
            auto &word = words[i];
            auto &next = nexts[i];
            while(p[i]>0&& letter!=word[p[i]]){
                p[i] = next[p[i]-1];
            }
            if(word[p[i]]==letter){
                p[i]++;
                
            }
            if(p[i]==word.size()){
                ret = true;
                p[i] = next[p[i]-1];
            }
        }
        return ret;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end
int main(){
    vector<string> words = {"abcabc"};
    StreamChecker s(words);
    s.query('a');
    s.query('b');
    s.query('c');
    s.query('a');
    s.query('b');
    s.query('c');
    s.query('a');
    s.query('b');
    s.query('c');
    
}
