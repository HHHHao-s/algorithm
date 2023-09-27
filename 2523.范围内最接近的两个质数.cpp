#include "s.h"
/*
 * @lc app=leetcode.cn id=2523 lang=cpp
 *
 * [2523] 范围内最接近的两个质数
 */

// @lc code=start
class Solution {
private:
    

    vector<bool> GetPrime(int max_num){
        vector<bool> ret(max_num+1, true);
        ret[0] = 0;
        ret[1] = 0;

        for(int i=2;i*i<=max_num;i++){
            for(int j=i*i;j<=max_num;j+=i){
                ret[j]=false;
            }
        }
        return ret;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime = GetPrime(right);

        int a=-1;
        int b=-1;
        int diff=INT_MAX;
        vector<int> ret({-1,-1});
        for(int i=left;i<=right;i++){
            if(prime[i]){
                if(a==-1){
                    a=i;
                }else{
                    b=a;
                    a=i;
                    if(diff > a-b){
                        ret[0] = b;
                        ret[1] = a;
                        diff = a-b;
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end

int main(){

    Solution s;
    auto ret= s.closestPrimes(4,6);
    cout << ret[0] << ' '<< ret[1];

    return 0;
}