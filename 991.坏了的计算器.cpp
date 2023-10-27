#include "s.h"
/*
 * @lc app=leetcode.cn id=991 lang=cpp
 *
 * [991] 坏了的计算器
 */

// @lc code=start
class Solution {

private:
    pair<int,int> countNum(int x){
        int cnt =0,high=0;
        for(int i=0;i<31;i++){
            if((1<<i)>x){
                break;
            }
            if((x & (1<<i))){
                cnt++;
                high=i;
            }
            
        }
        return {cnt,high};
    }


public:
    int brokenCalc(int startValue, int target) {
        
        if(target>startValue){
            int div = ((long long)target+startValue-1)/(long long)startValue;
            auto [cnt, high] = countNum(div);
            int diff=0;
            if(cnt==1){
                diff =startValue*(div)-target;
                auto [cnt2, high2] = countNum(diff);
                if(high2>high){
                    return (target&1)==0? 1 + brokenCalc(startValue, target/2):2+brokenCalc(startValue, target/2+1);
                }
                return cnt2+high;
            }else{
                diff =startValue*(1<<(high+1))-target;
                auto [cnt2, high2] = countNum(diff);
                if(high2>high){
                    return (target&1)==0? 1 + brokenCalc(startValue, target/2):2+brokenCalc(startValue, target/2+1);
                }
                return cnt2+high+1;
            }
            
            
            
        }
        
        return startValue-target;
            
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.brokenCalc(9,100);
}