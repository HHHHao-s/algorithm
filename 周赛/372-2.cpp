#include "../s.h"

class Solution {
public:
    long long minimumSteps(string s) {

        long long ans=0;
        int n = s.size();
        int j = 0;
        for(;j<n;j++){
            if(s[j]=='1'){
                break;
            }
        }
        if(j==n || j==n-1){
            // no 1
            return 0;
        }
        for(int i=j+1;i<n;i++){
            if(s[i]=='0'){
                swap(s[j], s[i]);
                ans += i-j;
                j++;
            }
        }
        return ans;

    }
};