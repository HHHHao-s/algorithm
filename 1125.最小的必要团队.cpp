#include "s.h"
/*
 * @lc app=leetcode.cn id=1125 lang=cpp
 *
 * [1125] 最小的必要团队
 */

// @lc code=start
class Solution {
private:
    unordered_set<int> ans;

    int ans_sz{16};
    int n{0};
    unordered_map<string,int> mp;
    unordered_map<int, unordered_set<int>> sp;
    vector<int> bss;
    
    void dfs(int need, unordered_set<int>& exist, int cur){

        if(need==0){
            if(ans_sz >= exist.size()){
                ans = exist;
                ans_sz = exist.size();
            }
            return ;
        }else if(cur==n){
            return ;
        }
        if((need & (1<< cur))==0){
            
            dfs(need, exist, cur+1);
        }else{
            if(exist.size()+1>=ans_sz){
                return;            
            }
            for(int nx: sp[cur]){
                if(!exist.count(nx)){
                    exist.insert(nx);
                    
                    dfs(need&(~bss[nx]), exist, cur+1);
                    exist.erase(nx);

                }   
            }
        }
        
        


    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int need=0;
        for(auto &string:req_skills){
            need |= (1<<n);
            mp[string] = n++;
            
        }
        
        int index=0;
        for(auto &strs: people){
            int bs=0;
            for(auto &str: strs){
                sp[mp[str]].insert(index);
                bs |= (1<<mp[str]);
            }
            index++;
            bss.push_back(move(bs));
            
        }

        unordered_set<int> exist;
        dfs(need, exist, 0);
        vector<int> as;
        for(auto x: ans){
            as.push_back(x);
        }
        return as;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> req={
        "algorithms","math","java","reactjs","csharp","aws"
    };
    vector<vector<string>> people={{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}};
    printArr(s.smallestSufficientTeam(req, people));
}