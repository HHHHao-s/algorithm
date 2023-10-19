#include "s.h"
/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start
template <typename T>
inline void hash_combine(std::size_t &seed, const T &val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
// auxiliary generic functions to create a hash value using a seed
template <typename T> inline void hash_val(std::size_t &seed, const T &val) {
    hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &... args) {
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        return hash_val(p.first, p.second);
    }
};

struct UnionFind{
    UnionFind(){}
    UnionFind(size_t n): arr(n){
        for(int i=0;i<n;i++){
            arr[i] = {i,1};
        }
    }

    int Find(int x){
        return arr[x].fa==x?x:(arr[x].fa=Find(arr[x].fa));
    }
    void Union(int fa, int son){
        int fax = Find(fa);
        int fay = Find(son);
        if(fax!=fay){
            arr[fax].cnt += arr[fay].cnt;
            arr[fay].fa = fax;
        }
    }
    int GetCnt(int x){
        return arr[Find(x)].cnt;
    }
    struct Info{
        int fa,cnt;
    };
    vector<Info>  arr;
};

class Solution {
private:
    int dir_x[4] = {0,1,0,-1};
    int dir_y[4] = {1,0,-1,0};
    int n;
    UnionFind uf;
    unordered_set<pair<int,int>, pair_hash> vis;
    
    
    void bfs(const vector<vector<int>>& grid, int x, int y){
        
        queue<pair<int,int>> q;

        q.push({x,y});
        vis.insert({x,y});
        
        
        while(!q.empty()){

            auto [tx,ty] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = dir_x[i]+tx;
                int ny = dir_y[i]+ty;
                if(nx>=0 && nx<n && ny>=0 && ny<n ){
                    if(!vis.count({nx,ny}) && grid[nx][ny]==1){
                        q.push({nx,ny});
                        vis.insert({nx,ny});
                        uf.Union( n*x+y, n*nx+ny);
                    }
                    
                }
            }

        }


    }

public:
    int largestIsland(const vector<vector<int>>& grid) {
        n = grid.size();
        uf = UnionFind(n*n);
             
        vector<pair<int,int>> fas;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis.count({i,j}) && grid[i][j]==1){
                    fas.push_back({i,j});
                    bfs(grid,i,j);
                }
            }
        }
        int ans = 0;
        
        if(fas.size()==1){
            return min(n*n, uf.arr[fas[0].first*n+fas[0].second].cnt+1);
        }else{
            
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    
                    if(grid[i][j]==0){
                        
                        int tmp=0;
                        unordered_set<int> tmp_vis;
                        for(int k=0;k<4;k++){
                            int nx = i+dir_x[k];
                            int ny = j+dir_y[k];
                            if(nx>=0 && nx<n && ny>=0 && ny<n){
                                if(grid[nx][ny]==1 && !tmp_vis.count(uf.Find(nx*n+ny))){
                                    tmp+=uf.GetCnt(nx*n+ny);
                                    tmp_vis.insert(uf.Find(nx*n+ny));

                                }
                            }
                            
                        }
                        ans = max(ans, tmp+1);
                        if(ans>=n*n){
                            return n*n;
                        }
                        
                    }
                    
                }
                
            }

        }
        return ans;
        
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.largestIsland({
        {1,0},
        {0,1}
    });

    return 0;
}