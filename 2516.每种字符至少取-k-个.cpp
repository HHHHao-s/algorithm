#include "s.h"
/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 *
 * [2516] 每种字符至少取 K 个
 */

// @lc code=start
class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0){
            return 0;
        }
        vector<int> cnt (3);
        vector<unordered_map<int,int>> pos(3);
        int n = s.size();

        for(int i=0;i<s.size();i++){
            char c = s[i];
            cnt[c-'a']++;
            pos[c-'a'][cnt[c-'a']] = i;
        }
        if(cnt[0]<k || cnt[1] < k || cnt[2] < k){
            return -1;
        }
        
        vector<int> have(3);
        int ret= max({pos[0][k],pos[1][k], pos[2][k]})+1;
        for(int j=0;j<3;j++){
            pos[j][0]=-1;
        }
        for(int r=s.size()-1;r>=0;r--){

            have[s[r]-'a']++;
            if(have[s[r]-'a']>k){
                have[s[r]-'a']=k;
            }
            int ml =0;
            for(int j=0;j<3;j++){
                ml = max(ml, pos[j][k-have[j]]+1);
            }
            if(ml>r){
                break;
            }
            ret = min(ret, ml+n-r);

        }
        return ret;

    }
};
// @lc code=end

