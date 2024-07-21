#include "../s.h"


class Solution {
public:
    int minChanges(int n, int k) {
        int ret = 0;
        if(n<k){
            return -1;
        }
        for(int i=1;i<=max(n,k);i<<=1){
            if((n & i) && ((k&i))==0){
                ret ++;
            }else if((n&i)==0 && (k&i)){
                return -1;
            }
        }
        return ret;

    }
};