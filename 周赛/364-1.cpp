#include "../s.h"

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int n = s.size();
        string ans(n,'1');
        int index=n-2;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans[index--] = '0';
            }
        }

        return ans;

    }
};