#include "../s.h"

class Solution {
public:
    typedef long long LL;
    int maximumXorProduct(long long a, long long b, int n) {
        for (int i = n - 1; i >= 0; --i) {
            LL x = 1;
            x <<= i;
            if ((a &x)==(b&x)) {
                a|=x, b|=x;
            } else {
                LL t1 = abs(a-b);
                LL t2 = abs((a^x)-(b^x));
                if (t2 < t1) {
                    a^=x;
                    b^=x;
                }
            }
        }
        const int M = 1000000007;
        a%=M;
        b%=M;
        a *= b;
        return a%M;
    }
};

int main(){
    Solution s;

    cout << s.maximumXorProduct(919266192685640, 877724646011187, 11);

    return 0;


}