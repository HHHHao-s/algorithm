#include "../s.h"

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        
        int n = s.size();
        int as=0;
        int bs= 0;
        int ans = 0;
        unordered_set<char> yuan={'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            if(yuan.count(s[i])){
                    as++;
            }else{
                bs++;
            }
            if(as==bs && (as*bs)%k==0){
                ans++;
            }
            for(int j=i+1;j<n;j++){
                if(yuan.count(s[j])){
                    as++;
                }else{
                    bs++;
                }
                if(as==bs && (as*bs)%k==0){
                    ans++;
                }
            }
            as = 0;
            bs = 0;
        }
        return ans;

    }
};
