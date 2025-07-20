#include "s.h"
/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

// @lc code=start
class Solution {
public:
    unordered_map<int,int> memo;


    int f(vector<vector<int>> &grid, int who,vector<int> &answer, vector<int>&quiet){

        if(memo.count(who)){
            return memo[who];
        }

        int mq = quiet[who];
        int mqp = who;

        for(int next: grid[who]){

            auto nmqp = f(grid, next, answer, quiet);
            
            if(mq > quiet[nmqp]){
                mq = quiet[nmqp];
                mqp = nmqp;
            }
        }
        
        answer[who] = mqp;
        memo[who] = mqp;

        return mqp;

    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
     
        int m = richer.size();
        int n = quiet.size();

        vector<int> answer(n, -1);

        vector<vector<int>> grid(n),rev_grid(n);

        for(const auto& rich: richer){

            int a = rich[0], b = rich[1];

            grid[a].push_back(b);
            rev_grid[b].push_back(a);


        }

        for(int i=0;i<n;i++){
            if(answer[i]==-1){
                f(rev_grid, i, answer, quiet);
            }
        }

        return answer;

    }
};
// @lc code=end



