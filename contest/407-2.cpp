#include "../s.h"

class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> have = {'a','e','i','o','u'};
        int h = 0;
        int all = s.size();

        for(char c: s){
            if(have.count(c)){
                h++;
            }
        }

        if(h==0){
            return false;
        }
        return true;
    }
};