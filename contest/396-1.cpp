#include "../s.h"

class Solution {
public:
    bool isValid(string word) {
        
        if(word.size()<3){
            return false;
        }
        int cnt = 0;
        int cnt2=0;
        unordered_set<char> yuan = {'a', 'e', 'i','o', 'u'};
        
        for(char c: word){
            if(c>='a' && c<='z'){
                if(yuan.count(c)){
                    cnt++;
                }else{
                    cnt2++;
                }
            }else if(c>='A' && c<='Z'){
                c = c-'A' + 'a';
                if(yuan.count(c)){
                    cnt++;
                }else{
                    cnt2++;
                }
            }else if(c>='0' && c<='9'){
                ;
            }else{
                return false;
            }

        }
        return cnt>0 && cnt2>0;

    }
};