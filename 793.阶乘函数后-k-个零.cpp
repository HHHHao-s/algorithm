#include "s.h"
/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

// @lc code=start
class Solution {
private:
    //  求x的阶乘的尾0数
    int zeta(long x) {
        int res = 0;
        while (x) {
            res += x / 5;
            x /= 5;
        }
        return res;
    }

    // 求尾数不小于k的最小数
    long long find(int k){
        long long r = 5LL*k;
        long long l = 0;

        while(l<=r){
            long long mid = (l+r)/2;
            long long zero_cnt = zeta(mid);
            if(zero_cnt<k){
                l = mid+1;
            }else{
                r = mid-1;
            }

        }
        return r+1;
    }


public:
    int preimageSizeFZF(int k) {
       
        
        return (int)(find(k+1)-find(k));

    }
};
// @lc code=end

int main(){


    Solution s;
    cout << s.preimageSizeFZF(100000000);
}