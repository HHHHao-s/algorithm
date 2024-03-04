#include "s.h"
/*
 * @lc app=leetcode.cn id=2812 lang=cpp
 *
 * [2812] 找出最安全路径
 */

// @lc code=start
struct UnionFind{
    UnionFind() = delete;

    UnionFind(size_t n): arr(n){
        for(int i=0;i<n;i++){
            arr[i] = {i,1};
        }
        region = n;
    }

    int Find(int x){
        return arr[x].fa==x?x:(arr[x].fa=Find(arr[x].fa));
    }
    void Union(int x, int y){
        int fax = Find(x);
        int fay = Find(y);
        if(fax!=fay){
            if(arr[fax].cnt<arr[fay].cnt){
                swap(fax, fay);
            }
            // 把fay合并到fax
            arr[fax].cnt += arr[fay].cnt;
            arr[fay].fa = fax;
            region--;
        }
    }
    int& GetCnt(int x){
        return arr[Find(x)].cnt;
    }

    struct Info{
        int fa,cnt;
    };
    vector<Info>  arr;
    int region{0};
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, -1));

        queue<tuple<int,int,int>> q;
        vector< vector<pair<int,int>>> dis_pos(n*3);
        for(int i= 0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j,0});
                    dis[i][j] = 0;
                    dis_pos[0].push_back({i,j});
                }
            }
        }
        int dirx[4] = {0,1,0,-1};
        int diry[4] = {1,0,-1,0};
        int top = 0;
        while(!q.empty()){
            auto [x,y, d] = q.front();
            q.pop();
            top = max(d, top);
            for(int i=0;i<4;i++){
                int nx = x+dirx[i];
                int ny = y+diry[i];
                if(nx>=0 && nx< n && ny>=0 && ny<n &&dis[nx][ny]==-1){
                    dis[nx][ny] = d+1;
                    q.push({nx, ny, d+1});
                    dis_pos[d+1].push_back({nx,ny});
                }
            }
        }

        UnionFind uf(n*n +10    );
        vector<vector<int>> vis(n, vector<int>(n, 0));
        for(int i=top;i>=0;i--){
            for(auto [x,y] : dis_pos[i]){
                for(int i=0;i<4;i++){
                    int nx = x+dirx[i];
                    int ny = y+diry[i];
                    if(nx>=0 && nx< n && ny>=0 && ny<n &&vis[nx][ny]){
                            uf.Union(nx*n+ny, x*n+y);    
                    }
                }
                vis[x][y] = 1;
                if(uf.Find(0) == uf.Find(n*n-1)){
                    return i;
                }
            }

        }
        return 0;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> grid={
        {0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}
    };
    cout << s.maximumSafenessFactor(grid);
}