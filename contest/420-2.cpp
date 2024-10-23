#include "../s.h"

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;i++){

            vector<int> have(26);
            for(int j=i;j>=0;j--){

                have[s[j]-'a']++;
                if(have[s[j]-'a']>=k){
                    ans+= j+1;
                    break;
                }

            }

        }

        return ans;
        

    }
};