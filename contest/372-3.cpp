#include "../s.h"

class Solution {
public:
    typedef long long LL;
    int maximumXorProduct(long long a, long long b, int n) {
        long long dis = 0;
        long long mask = (1ll<<n)-1;
        int r=0;
        long long ra=0, rb=0;
        if(b>a){
            swap(a,b);
        }
        for (int i = n - 1; i >= 0; --i) {
            LL x = 1;
            x <<= i;
            if ((a &x)==(b&x)) {
                ra|=x, rb|=x;
            } else {
                if(dis==0){
                    r = i;
                }
                dis += x;
            }
        }
        const int M = 1000000007;
        long long ma = a&(~mask) | ra;
        long long mb = b&(~mask) | rb;
        if(ma!=mb || dis==0){
            mb+=dis;
            return ((mb%M)*(ma%M))%M;
        }else{
            
            return (((mb+(1ll<<r))%M)*((ma+(dis ^ (1ll<<r)))%M))%M;
        }
        return 0;
    }
};

int main(){
    Solution s;

    cout << s.maximumXorProduct(919266192685640, 877724646011187, 11);

    return 0;


}