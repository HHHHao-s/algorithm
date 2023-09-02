#include "s.h"
/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> out(n+1);
        vector<int> in(n+1);

        for(auto it: trust){
            int a = it[0];
            int b = it[1];
            out[a]++;
            in[b]++;
        }

        int cnt=0, id=-1;
        for(int i=1;i<=n;i++){
            if(out[i]==0 && in[i]==n-1){
                cnt++;
                id = i;
            }
        }

        if(cnt==1){
            return id;
        }else{
            return -1;
        }


    }
};
// @lc code=end

