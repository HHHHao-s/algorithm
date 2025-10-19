#include "s.h"
/*
 * @lc app=leetcode.cn id=1156 lang=cpp
 *
 * [1156] 单字符重复子串的最大长度
 */

// @lc code=start
class Solution {
public:
    int maxRepOpt1(string text) {
        
        int ret = 1;
        vector<vector<pair<int,int>>> vec(26);
        for(int i=0;i<text.size();i){

            int j= i+1;
            while(j<text.size() && text[j]==text[i]){
                j++;
            }
            ret = max(ret, j-i + (vec[text[i]-'a'].size()>0));
            vec[text[i]-'a'].push_back({i,j});
            
            i = j;

        }

        for(int a=0;a<26;a++){

            if(vec.size()<=1){
                continue;
            }
            for(auto it = vec[a].begin(); it!=vec[a].end(); it++){
                auto nxt = next(it);
                if(nxt== vec[a].end()){
                    break;
                }
                if(it->second==nxt->first-1){
                    auto nnxt = next(nxt);
                    if(it!=vec[a].begin() || nnxt != vec[a].end()){
                        ret = max(ret, it->second-it->first + nxt->second-nxt->first + 1);
                    }else{
                        ret = max(ret,it->second-it->first + nxt->second-nxt->first );
                    }
                }else{
                    ret = max({ret, it->second-it->first+1});
                }

            }

        }

        return ret;

        

    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.maxRepOpt1("babbaaabbbbbaa");
}