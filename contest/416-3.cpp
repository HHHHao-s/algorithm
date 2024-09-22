#include "../s.h"

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        
        long long ans =0;

        vector<int> cnt (26);
        int diff=word2.size();
        for(char c : word2){
            cnt[c-'a']++;
            
        }
        vector<int> have(26);

        
        vector<int> cursor(26);

        for(int i=0;i<word1.size();i++){

            char c = word1[i]-'a';
            if(cnt[c]){
                if(have[c]==cnt[c]){
                    do{
                        cursor[c]++;
                    }while(word1[ cursor[c]]!=c+'a');
                }else{

                    have[c]++;
                    if(have[c]==1){
                        cursor[c] = i;
                    }
                    diff--;
                }
            }
            int left_most=INT_MAX;
            if(diff==0){
                for(int j =0;j<26;j++){
                    if(cnt[j]==0){
                        continue;
                    }
                    left_most = min(left_most, cursor[j]);
                }
                ans+=left_most+1;
            }
        }
        return ans;

    }
};
int main(){
    Solution s;
    cout << s.validSubstringCount("abcabc", "abc");
}