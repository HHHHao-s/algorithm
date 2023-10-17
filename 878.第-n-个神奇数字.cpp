#include "s.h"
/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start
class Solution {
private:
    long long rc(long long n, long long m){
        return n/m;
    }

public:
    int nthMagicalNumber(int n, int a, int b) {
        long long high=(long long)max(a,b)*(long long)n;

        long long axb = (long long)a*(long long)b/gcd(a,b);
        // if((a>b&&(a%b==0))||(a<b&&(b%a==0))){
        //     return (int)(((long long)n*min(a,b))%1000000007);
        // }

        long long low = 2;
        long long ans= 1;
        while(low<=high){

            long long mid = low + (high-low)/2;
            long long test = rc(mid, a)+rc(mid,b)-rc(mid, axb);
            if(test<n){

                low = mid+1;
                
            }else if(test>n){
                high = mid-1;
            }else{
                ans = mid;
                break;
            }

        }
        long long tmp1 = (ans/a)*a;
        long long tmp2 = (ans/b)*b;
        long long tmp3 = (ans/(axb))*(axb);

        ans = max({tmp1,tmp2,tmp3});

        return (int)(ans%1000000007);

    }
};
// @lc code=end

int main(){
    Solution s;

    cout << s.nthMagicalNumber(1000000000,40000,40000);

    return 0;
}