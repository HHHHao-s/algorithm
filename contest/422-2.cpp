#include "../s.h"

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> low(m ,vector<int>(n, INT_MAX));

        queue<pair<int, int> > q;
        q.push({0,0});
        low[0][0] = 0;

        int dirx[4] = {0,1,-1,0};
        int diry[4] = {1,0,0,-1};

        while(!q.empty()){

            auto [x, y] = q.front();
            q.pop();
            

            for(int i=0;i<4;i++){
                int nx = x+dirx[i];
                int ny = y+diry[i];
                if(nx<0 || nx>=m || ny<0 || ny>=n){
                    continue;
                }
                int next = max(low[x][y]+1, moveTime[nx][ny]+1);
                if(low[nx][ny]>next){
                    low[nx][ny] = next;
                    q.push({nx,ny});
                }
            }
        }
        return low[m-1][n-1];

    }
};

int main(){
    vector<vector<int>> grid={
        {0,4},
        {4,4}
    };
    cout << Solution().minTimeToReach(grid);
}