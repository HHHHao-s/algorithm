#include "s.h"
/*
 * @lc app=leetcode.cn id=2156 lang=cpp
 *
 * [2156] 查找给定哈希值的子串
 */

// @lc code=start
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

class Solution {
public:
    string subStrHash(string s, int p, int m, int k, int h) {
        vector<int> vals;
        for(char c: s){
            vals.push_back(c-'a'+1);
        }
        int n = s.size();
        long long cur = 0;
        for(int i=n;i-->n-k+1;){
            cur = ((cur*p)%m+vals[i])%m;    
        }
        int ret=INT_MAX;
        long long ppk = power(p,k-1,m);
        
        for(int i=n-k;i>=0;i--){

            cur = ((cur*p)%m+vals[i])%m;
            if(cur<0){
                cur+= m;
            }
            if(cur==h)
                ret = min(ret, i);
            cur = (cur-(vals[i+k-1]*ppk)%m)%m;

        }
        return s.substr(ret, k);
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.subStrHash("leetcode", 7,20,2,0);
}