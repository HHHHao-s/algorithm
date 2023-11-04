#include "s.h"
/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
 */

// @lc code=start
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int up_bound = n*n;
        auto get = [&](int index){
            int d = (index-1)/n;
            int mo = (index-1)%n;
            int x = n-1-d;
            int fr = d%2;
            if(fr==1){
                // nixu
                return board[x][n-1-mo];
            }else{
                return board[x][mo];
            }

        };
        
        queue<int> q;
        vector<int> vis(n*n+1,0);
        q.push(1);
        int step=0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto cur = q.front();
                q.pop();
                if(cur == up_bound){
                    return step;
                }

                for(int j=1;j<=6;j++){
                    if(cur+j>up_bound){
                        break;
                    }
                    int climb = get(cur+j);
                    if(climb!=-1 && !vis[cur+j]){
                        
                        q.push(climb);
                        vis[cur+j] = 1;
                          
                    }else{
                        if(!vis[cur+j]){

                            q.push(cur+j);
                            vis[cur+j] = 1;
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

int main(){
    Solution s;
    // vector<vector<int>> board={{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    vector<vector<int>> board={
        {1,1,-1},
        {1,1,1},
        {-1,1,1}
    };
    cout << s.snakesAndLadders(board);

}