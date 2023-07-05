#include "s.h"
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:

    

    void my(vector<vector<int>>& ret,const vector<int>& candidates, int target, vector<int>& cur, int now, int sum) {
        if(target==sum){
            ret.push_back(cur);
            return;
        }else if(sum>target){
            return;
        }
        for(int i=now;i<candidates.size();i++){
            int it = candidates[i];
            if(it+sum>target) break;
            cur.push_back(it);
            my(ret, candidates, target,cur, i, sum+it );
            cur.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 从小到大弄
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> ret;
        my(ret, candidates, target, cur, 0, 0);
        return ret;
    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> candidates = {2,3,5};
    print2d(s.combinationSum(candidates, 8));


    return 0;
}