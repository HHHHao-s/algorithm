#include "../s.h"

class Solution {
public:
    int maxOperations(string s) {
        
        int j=0;
        int n = s.size();
        int ret = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                j++;
            }
            if(s[i]=='0'){
                ret+=j;
                while(i+1<n && s[i+1]=='0'){
                    i++;
                }
            }

        }
        return ret;

    }
};