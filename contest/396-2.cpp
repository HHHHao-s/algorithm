#include "../s.h"

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> cnt;
        for(int i=0;i<word.size();i+=k){
            cnt[word.substr(i, k)] ++;
        }
        int mx=0;

        for(auto [s, ct]: cnt){
            mx = max(mx, ct);
        }
        return word.size()/k -mx;

    }
};