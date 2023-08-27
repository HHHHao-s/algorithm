#include "s.h"
/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> visited, bnk;
        char keys[4] = {'A', 'C', 'G', 'T'}; 
        for(auto s:bank){
            bnk.insert(s);
        }

        if (startGene == endGene) {
            return 0;
        }
        if (!bnk.count(endGene)) {
            return -1;
        }

        queue<string> q;

        q.push(startGene);
        visited.insert(startGene);
        int step=1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                string curr = q.front();
                q.pop();
                for(int j=0;j<8;j++){
                    for(int k=0;k<4;k++){
                        
                        if(keys[k]!=curr[j]){
                            string next = curr;
                            next[j] = keys[k];
                            if(!visited.count(next) && bnk.count(next)){
                                if(endGene==next){
                                    return step;
                                }
                                visited.insert(next);
                                q.push(next);
                            }
                        }
                    }
                }
            }
            step++;
        }

        return -1;
    }
};
// @lc code=end

