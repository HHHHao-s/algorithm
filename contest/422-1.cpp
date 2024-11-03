#include "../s.h"


class Solution {
public:
    bool isBalanced(string num) {
        int l=0,r=0;
        for(int i=0;i<num.size();i++){
            if(((i+2)%2 )== 1){
                l+=num[i]-'0';
            }else{
                r+=num[i]-'0';
            }
        }
        return l==r;
    }
};