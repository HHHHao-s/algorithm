#include "s.h"
/*
 * @lc app=leetcode.cn id=2101 lang=cpp
 *
 * [2101] 引爆最多的炸弹
 */

// @lc code=start
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        vector<int> can(n, 1);
        int cant = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    int xdis= (bombs[i][0] - bombs[j][0]);
                    int ydis= (bombs[i][1] - bombs[j][1]);
                    if(xdis*xdis + ydis*ydis <= bombs[i][2]*bombs[i][2]){
                        graph[i].push_back(j);
                        if(can[j]){
                            cant++;
                        }
                        can[j] = 0;
                        
                    }
                }
            }

        }
        if(cant==n){
            return n;
        }
        int ans= 1;
        vector<int>visit(n, 0);
        for(int i=0;i<n;i++){
            if(can[i] && !visit[i]){
                int tmp = 1;
                queue<int> q;
                q.push(i);
                visit[i] = 1;
                while(!q.empty()){

                    int a = q.back();
                    q.pop();
                    for(int next: graph[a]){
                        if(visit[next]){
                            continue;
                        }
                        q.push(next);
                        visit[next]= 1;
                        tmp++;


                    }

                }
                ans = max(ans, tmp);
            }
        }
        return ans;


    }
};
// @lc code=end

int main(){
    return 0;
}