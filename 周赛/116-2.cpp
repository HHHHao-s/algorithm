#include "s.h"

class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i+=2){
            if((s[i]=='1' && s[i+1]=='0') || (s[i]=='0' && s[i+1]=='1')){
                ans++;
            }
        }
        return ans;


    }
};