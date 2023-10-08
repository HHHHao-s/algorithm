#include "../s.h"

class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        int first = m;
        int cnt = n/m;
        int last = cnt*m;
        int num2 = (first+last)*cnt/2;
        int num1 = n*(1+n)/2 - num2;
        return num1-num2;
    }
};