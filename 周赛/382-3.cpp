#include "../s.h"
class Solution {
public:
    long long flowerGame(int n, int m) {
        
        

        long long nj = (n+1)/2;
        long long no = n-nj;
        long long mj = (m+1)/2;
        long long mo = m-mj;
        return nj*mo + no*mj;


    }
};