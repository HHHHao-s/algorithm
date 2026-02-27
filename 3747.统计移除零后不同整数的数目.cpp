#include "s.h"
#include <algorithm>
/*
 * @lc app=leetcode.cn id=3747 lang=cpp
 *
 * [3747] 统计移除零后不同整数的数目
 */

// @lc code=start
class Solution {
public:
    long long countDistinct(long long n) {
        if(n<10){
            return n;
        }
        vector<int> each;
        long long cur = 1;
        for(int i=0;i<16;i++){
            if(n<cur){
                break;
            }
            each.push_back((n/cur) % 10);
            cur *= 10;
        }
        ranges::reverse(each);
        long long ret = 0;
        long long nines = 9;
        for(int i=1;i<each.size();i++){
            ret += nines;
            nines *= 9;
        }
        long long p9 = pow(9, each.size()-1);
        for( int i=0;i<each.size() ;i++){
            if(each[i]==0){
                break;
            }
            long long d = each[i]-1;
            if(i == each.size()-1){
                d++;
            }

            ret += p9 * d;
            p9/=9;
        }

        return ret;

    }
};
// @lc code=end

