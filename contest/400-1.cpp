#include "../s.h"

class Solution {
public:
    int minimumChairs(string s) {

        int mx = 0;
        int cur = 0;
        for(char c: s){
            if(c=='E'){
                cur--;
                if(cur<0){
                    mx++;
                    cur=0;
                }
                
            }else{
                cur++;
            }
        }
        return mx;

    }
};