#include "s.h"
/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] 确定两个字符串是否接近
 */

// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1!=n2){
            return false;
        }
        vector<int> cnt1(26), cnt2(26);
        
        for(int i=0;i<n1;i++){
            cnt1[word1[i]-'a']++;
            cnt2[word2[i]-'a']++;

        }
        
        for(int i=0;i<26;i++){
            if(cnt1[i]==0 && cnt2[i]!=0 || cnt1[i]!=0 && cnt2[i]==0){
                return false;
            }
            
            
        }
        
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        


        
        return cnt1==cnt2;
    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.closeStrings("abc","bca");
}