#include "s.h"
/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * [932] 漂亮数组
 */

// @lc code=start
class Solution {
private:
    unordered_map<int,vector<int>> memo;

public:
    vector<int> beautifulArray(int n) {
        if(n==1){
            return {1};
        }else if(n==2){
            return {1,2};
        }
        if(memo.count(n)){
            return memo[n];
        }
        vector<int> a1 = beautifulArray((n+1)/2);
        vector<int> a2 = beautifulArray(n/2);
        vector<int> ans;
        for(int x: a1){
            ans.push_back(2*x-1);

        }
        for(int x: a2){
            ans.push_back(2*x);
        }
        memo[n] = ans;
        return ans;


    }
};
// @lc code=end

int main(){
    Solution s;
    printArr(s.beautifulArray(5));
}