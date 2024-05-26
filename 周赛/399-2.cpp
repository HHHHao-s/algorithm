#include "../s.h"

class Solution {
public:
    string compressedString(string word) {
        string ret;
        
        for(int i=0;i<word.size();){
            int j =i;
            char c = word[i];
            while(i<word.size() && word[i]==c && i-j <9){
                i++;
            }
            ret += to_string(i-j);
            ret.push_back(c);
        }

        return ret;

    }
};