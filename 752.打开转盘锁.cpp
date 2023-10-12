#include "s.h"
/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
private:
    unordered_set<string> vis;
    

public:
    int openLock(vector<string>& deadends, string target) {
        

        for(auto &s: deadends){
            vis.insert(s);
        }
        if(vis.count("0000")){
            return -1;
        }
        if(target == "0000"){
            return 0;
        }

        vis.insert({"0000"});

        queue<string> q;

        q.push("0000");

        int step=0;
        while(!q.empty()){
            step++;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                
                string s = q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    string ns = s;
                    string ls = s;
                    ns[j] = (((s[j]-'0')+1)%10)+'0';
                    ls[j] = ((((s[j]-'0')-1)+10)%10)+'0';
                    if(target==ls || target==ns){
                        return step;
                    }
                    if(!vis.count(ls)){
                        q.push(ls);
                        vis.insert(ls);
                    }
                    if(!vis.count(ns)){
                        q.push(ns);
                        vis.insert(ns);
                    }
                    
                }

            }
            
        }
        return -1;
    }
};
// @lc code=end

