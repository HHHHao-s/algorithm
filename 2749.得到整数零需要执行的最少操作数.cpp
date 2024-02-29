#include "s.h"
/*
 * @lc app=leetcode.cn id=2749 lang=cpp
 *
 * [2749] 得到整数零需要执行的最少操作数
 */

// @lc code=start


class Solution {


public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1<num2+1){
            return -1;
        }

        long long n1 = num1, n2= num2;


        for(long long i=1;i<10000;i++){
            long long x= n1-i*n2;
            if(n2>0 && x< i){
                return -1;
            }else{
                int cnt= 0;
                for(int index=0;index<64;index++){
                    if(x&(1ll<<index)){
                        cnt++;
                    }
                }
                if(cnt<=i){
                    return i;
                }

            }
        }

        
        return -1;

    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.makeTheIntegerZero(112577768,-501662198);
}