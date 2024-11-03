#include "../s.h"

struct Nd{
    int x, y ,d, s;

    bool operator<(const Nd& rhs)const{
        return d > rhs.d;
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        int m = moveTime.size();
        int n = moveTime[0].size();

        priority_queue<Nd> pq;

        pq.push({0,0,0,0});
        int dirx[4] = {0,1,0,-1};
        int diry[4] = {1,0,-1,0};

        vector<vector<int>> dis(m , vector<int>(n,INT_MAX)), visit(m ,vector<int>(n, 0));
        visit[0][0] =1;
        dis[0][0] = 0;
        while(!pq.empty()){

            auto [x ,y ,d, s] = pq.top();
            pq.pop();
            
            for(int i=0;i<4;i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx<0 || nx>=m || ny<0 || ny>=n){
                    continue;
                }
                if(visit[nx][ny]){
                    continue;
                }
                dis[nx][ny] = max(dis[x][y], moveTime[nx][ny])+ 1+ (s%2);
                pq.push({nx, ny, dis[nx][ny] , s+1});
                visit[nx][ny] =1;
            }


        }

        return dis[m-1][n-1];

        


    }
};

int main(){
    vector<vector<int>> grid={
        {0,58},
        {27,69}
    };
    cout << Solution().minTimeToReach(grid);
}