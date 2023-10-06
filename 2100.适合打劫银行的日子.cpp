#include "s.h"
/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();

        if(time*2+1>n){
            return {};
        }
        if(time==0){
            vector<int> ret(n);
            for(int i=0;i<n;i++){
                ret[i]=i;
            }
            return ret;
        }

        vector<bool> pre(n,false);
        int cnt=1;
        

        for(int i=1;i<n;i++){
            if(security[i-1]>=security[i]){
                if(cnt==time){
                    pre[i]=true;
                }else{
                    cnt++;
                }

            }else{
                cnt = 1;
            }
        }
        cnt = 1;
        vector<int> ret;
        for(int i=n-1;i-->0;){
            if(security[i]<=security[i+1]){
                if(cnt==time){
                    if(pre[i] == true){
                        ret.push_back(i);
                    }
                    
                }else{
                    cnt++;
                }
            }else{
                cnt = 1;
            }
        }

        return ret;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> sec = {
        1,2,5,4,1,0,2,4,5,3,1,2,4,3,2,4,8
    };
    printArr(s.goodDaysToRobBank(sec, 2));

    return 0;
}