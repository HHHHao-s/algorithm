#include "s.h"
/*
 * @lc app=leetcode.cn id=866 lang=cpp
 *
 * [866] 回文素数
 */

// @lc code=start
class Solution {
private:
    bool is_palindrome(int x) {
        if (x < 0) {
            return false;
        }
        int y = 0, z = x;
        while (z > 0) {
            y = y * 10 + z % 10;
            z /= 10;
        }
        return x == y;
    }
    bool is_prime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int primePalindrome(int n) {
        if(n==1){
            return 2;
        }
        if(n>=10000000 && n<100000000)  //长度是8位的没有素数:这个结论我不知道~~哈哈
            n=100000000;
        for(int i=n;i<2*1e8;i++){
            


            if(is_palindrome(i)&&is_prime(i)){
                return i;
            }

        }

        return 0;
    }
};
// @lc code=end



int main(){

    

    return 0;
}