#include "../s.h"

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int cnt = 0;
        vector<int> v(26);
        for(char c: word){
            if(c>='a' && c<='z'){
                v[c-'a']|=1;
                
            }else if(c>='A' && c<='Z'){
                v[c-'A']|=2;
                
            }
        }
        for(int i=0;i<26;i++){
            if(v[i]==3){
                cnt++;
            }
        }
        return cnt;

    }
};