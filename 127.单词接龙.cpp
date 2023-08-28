#include "s.h"
/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord,const vector<string>& wordList) {

        int word_n = beginWord.size();

        unordered_set<string> wordSet, vis;
        vector<unordered_set<char>> each_word(word_n);

        int flag=0;
        for(auto s: wordList){
            wordSet.insert(s);

            if(s==endWord) flag = 1;

            int sn = s.size();
            for(int i=0;i<sn;i++){
                each_word[i].insert(s[i]);// 记录此位置可以进行替换的char
            }
        }
        if(!flag){
            return 0;
        }
        

        queue<string> q;

        q.push(beginWord);
        vis.insert(beginWord);
        int step=1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                string s = q.front();
                cout << s << endl;
                q.pop();

                for(int j=0;j<word_n;j++){
                    for(char word:each_word[j]){
                        string next = s;
                        next[j] = word;
                        if(vis.count(next)){
                            continue;
                        }

                        if(wordSet.count(next) && endWord != next){
                            q.push(next);
                            vis.insert(next);
                        }else if(endWord == next){
                            return step+1;
                        }
                    }
                }

            }
            step++;

        }

        return 0;

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.ladderLength("hit", "cog", {
        "hot","dot","dog","lot","log","cog"
    });

    return 0;
}