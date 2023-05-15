#include "s.h"
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {



        unordered_map<char, int> cnt, map;
        string ans;
        int ns= s.size(), nt = t.size();
        if(nt>ns){return ans;};
        for(int i=0;i<nt;i++){
            map[t[i]] = 1;
            cnt[t[i]]++;
        }
        int l=0,r=0, left=0, right=0, len=INT32_MAX, need=nt, begin=0;

        while(r<ns){
            
            if(map.count(s[r])){
                // 需要此词语
                int a = cnt[s[r]];
                if(a>0){
                    cnt[s[r]]--;
                    need--;
                }else{
                    cnt[s[r]]--; // 有重复
                }
                
            }
            while(need==0 && l<=r){ 
                if(map.count(s[l])){ // 操作
                    if(cnt[s[l]]>=0){
                        if((r-l+1)<len){
                            len = r-l+1; // 记录窗口最大值
                            ans = s.substr(l,len);
                        }
                        // 下一步need不等于零，这时就是最佳的子串
                        cnt[s[l]]++;
                        need++;
                    }else{// 重复
                        cnt[s[l]]++;
                    }
                }
                l++;
            }

            if(len<(r-l)){ // 窗口比现在的大
                if(map.count(s[l])){ // 操作
                    if(cnt[s[l]]>=0){
                        cnt[s[l]]++;
                        need++;
                    }else{
                        cnt[s[l]]++;
                    }
                }
                l++;
            }
            r++;
        }

        return ans;




    }
};
// @lc code=end

int main(){

    Solution so;

    string s = "ABBBBBBBBBBBBBBBBBBCBBBBBA";
    string t = "ABC";

    cout << so.minWindow(s,t);


    



    return 0;
}
