#include "../s.h"

class Solution {
public:
    int countKeyChanges(string s) {

        int index = 0;
        int ans = 0;
        while(index<s.size()){
            int next = index+1;
            
            while(next<s.size()&&(s[index]==s[next] || abs(s[index]-s[next])=='a'-'A')){
                next++;
            }
            ans++;
            index = next;

        }

        return ans-1;
    }
};