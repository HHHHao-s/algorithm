#include "s.h"
/*
 * @lc app=leetcode.cn id=1547 lang=cpp
 *
 * [1547] 切棍子的最小成本
 */

// @lc code=start
class Solution {
private:
    int ans;
    unordered_map<int, unordered_map<int,unordered_map<int,int>>> memo;
    int hash1(int li ,int ri){
        return li*100+ri;
    }
    

    int cut(int l, int r, vector<int> &cuts, int li, int ri){
        if(li>ri){
            return 0;
        }
        if(li==ri){
            return r-l;
        }
        if(memo[hash1(li,ri)][l].count(r)){
            return memo[hash1(li,ri)][l][r];
        }

        int ret=INT_MAX;
        for(int i=li;i<=ri;i++){
            int nc = cuts[i];
            int left = cut(l, nc, cuts, li, i-1);

            int right = cut(nc, r, cuts, i+1, ri);

            ret = min(ret,r-l+ left+right);
        }
        memo[hash1(li,ri)][l][r]=ret;
        return ret;  
    }

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        return cut(0,n,cuts, 0, cuts.size()-1);

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> cuts = {1,3,4,5};
    cout << s.minCost(7, cuts);
}