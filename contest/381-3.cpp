#include "../s.h"

class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> appear(26);
        for(char c: word){
            appear[c-'a']++;
        }
        sort(appear.begin(), appear.end(), greater<int>());
        int index=0;
        int ans = 0;
        for(int i=0;i<26;i++){
            ans += (index/8 + 1 )*appear[i];
            index++;
        }
        return ans;


    }
};