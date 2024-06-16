#include "../s.h"

class Solution {
public:
    int minAnagramLength(string s) {

        vector<int> cnt(26);
        for(char c: s){
            cnt[c-'a']++;
        }
        int g = cnt[0];
        for(int i=1;i<26;i++){
            g = gcd(g, cnt[i]);
        }
        int sz = 0;
        for(int i=0;i<26;i++){
            sz += cnt[i]/g;
        }
        return sz;

    }
};