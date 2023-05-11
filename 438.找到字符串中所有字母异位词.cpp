#include "s.h"
/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 需要回看
        vector<int> ans;

        int ns = s.size(),np = p.size();

        if(np>ns){return ans;};

        int cnt[26]={0};


        
        for(auto it:p){
            cnt[it-'a']++;
        }


        for(int l=0,r=0;r<np;r++){
            cnt[s[r]-'a']--;
            while(cnt[s[r]-'a']<0){
                cnt[s[l]-'a']++;
                l++;
            }
            if(r-l+1==np){
                ans.push_back(l);
            }
        }

        return ans;

    
    }

};
// @lc code=end

