#include "../s.h"


class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        string ret;
        int n  = s.size();
        for(int i=0;i<n;i++){
            ret.push_back( s[(i+k)%n] );
        }
        return ret;

    }
};