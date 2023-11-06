#include "s.h"
/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {

        vector<int> bit_set_arr(words.size());
        constexpr int all = (1<<26)-1;
        for(int i=0;i<words.size();i++){
            int bs = 0;
            auto & word = words[i];
            for(int j=0;j<word.size();j++){
                bs |= (1<<(word[j]-'a'));
                if(bs==all){
                    break;
                }
            }
            bit_set_arr[i] = bs;
        }
        int ans = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if((bit_set_arr[i]&bit_set_arr[j])==0){// 无交集
                    ans= max(ans,(int)(words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

