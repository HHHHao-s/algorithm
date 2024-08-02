#include "s.h"
/*
 * @lc app=leetcode.cn id=1354 lang=cpp
 *
 * [1354] 多次求和构造目标数组
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& target) {

        
        
        multiset<int> s;
        long long sum = 0;
        for(int i: target){
            s.insert(i);
            sum += i;
        
        }
        
        if(target.size()==1){
            return target[0]==1;
        }



        while(1){
            auto m = *s.rbegin();
            if(m==1){
                return true;
            }

            s.extract(m);
            sum-= m;
            auto m2 = *s.rbegin();
            long long k = (m - m2-1)/sum +1 ;
            if(m-k*sum<=0){
                return false;
            }
            


            s.insert(m-k*sum);
            sum += m-k*sum;
        }
        return true;



    }
};
// @lc code=end

