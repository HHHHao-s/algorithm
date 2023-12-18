#include "s.h"
/*
 * @lc app=leetcode.cn id=2246 lang=cpp
 *
 * [2246] 相邻字符不同的最长路径
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> grid;
    int ans{0};
    unordered_map<int ,int> memo;
    int dfs(int fa, int node,const string& s){
        if(memo.count(node)){
            return memo[node];
        }
        int a=0;
        int b=0;
        
        for(int x: grid[node]){
            if(x!=fa){
                
                int no_fa = dfs(node, x , s);
                if(no_fa>a){
                    b=a;
                    a=no_fa;
                }else if(no_fa>b){
                    b=no_fa;
                }
                
            }
        }
        ans = max(ans, a+b+1);

        if(fa!=-1 && s[fa]==s[node]){
            memo[node] = 0;
            return 0;
        }else{
            memo[node] = a+1;
            return a+1;
        }
        return -1; // ignore


       

    }

public:
    int longestPath(vector<int>& parent, string s) {

        grid= vector<vector<int>>(parent.size());
        for(int i=1;i<parent.size();i++){
            
            grid[i].push_back(parent[i]);
            grid[parent[i]].push_back(i);
        }

        bitset<26> have;
        dfs(-1, 0, s);
        return ans;



    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> parent = {-1,0,1,2,3,4};
    cout << s.longestPath(parent, "zzabab");
}