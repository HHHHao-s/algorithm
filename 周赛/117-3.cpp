#include "../s.h"




class Solution {
private:
const long long m=1e9+7;
    long long quickpow(long long a,long long b){
        long long sum=1;
        while(b){
            if(b&1)//与运算，可判断奇偶，详细见注释
            sum=sum*a%m;//取模运算
            a=a*a%m;
            b>>=1;//位运算，右移，相当于除以2
        }
        return sum;
    }
    const long long MOD = 1000000007;


public:
    int stringCount(int n) {
        


        if(n<4){
            return 0;
        }else if(n==4){
            return 12;
        }
        
        long long e = quickpow(25,n)+(n*quickpow(25,n-1))%MOD;
        long long t = quickpow(25,n);
        long long l = quickpow(25,n);
        long long et = quickpow(24,n) + (n*quickpow(24,n-1))%MOD;
        long long el = et;
        long long lt = quickpow(24,n);
        long long leet = quickpow(23,n)+(n*quickpow(23,n-1))%MOD;

        long long ans= (quickpow(26,n)-(e+t+l-et-el-lt+leet)%MOD)%MOD;
        if(ans <0){
            return ans +MOD;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.stringCount(10);
}