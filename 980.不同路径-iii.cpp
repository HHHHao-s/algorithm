#include "s.h"
/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
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

class Solution {
private:
    

    unordered_set<pair<int,int>, pair_hash> path;
    int dir_x[4] = {0,1,0,-1};
    int dir_y[4] = {1,0,-1,0};
    int ans{0};
    int need{0};

    void dfs(vector<vector<int>>& grid, int x, int y){
        for(int i=0;i<4;i++){
            int nx = x+dir_x[i];
            int ny = y+dir_y[i];
            if(nx>=0 && nx<grid.size() && ny>=0&&ny<grid[0].size()&&path.count({nx,ny})==0){
                
                if(grid[nx][ny]==2){
                    if(need==path.size()){
                        ans++;
                    }
                    
                }else if(grid[nx][ny]==0){
                    path.insert({nx,ny});
                    dfs(grid, nx, ny);
                    path.erase({nx,ny});
                }
            }
        }
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int bx=0,by=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    bx=i;
                    by=j;
                    need++;
                }else if(grid[i][j]==0){
                    need++;
                }
            }
        }
        path.insert({bx,by});
        dfs(grid, bx, by);
        return ans;

    }
};
// @lc code=end

int main(){


    return 0;
}