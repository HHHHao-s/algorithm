#include "s.h"
/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
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
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, uint16_t> row, col, right, left;
        unordered_set<pair<int,int>, pair_hash> lamp_map;
        for(auto &node: lamps){
            
            int x = node[0];
            int y = node[1];
            if(lamp_map.count({x,y})==1){
                continue;
            }
            row[x]++;
            col[y]++;
            right[n-y+x-1]++;
            left[x+y]++;
            lamp_map.insert({x,y});
        }
        
        vector<int> ret;
        for(auto &query_node: queries){
            int x = query_node[0];
            int y = query_node[1];
            if(row[x] || col[y] || right[n-y+x-1] || left[x+y]){
                ret.push_back(1);
            }else{
                ret.push_back(0);
            }
            for(int i=x-1;i<=x+1;i++){
                for(int j=y-1;j<=y+1;j++){
                    if(i>=0 && i<n && j>=0 && j<n){
                        if(lamp_map.count({i,j})){
                            lamp_map.erase({i,j});
                            row[i]--;
                            col[j]--;
                            right[n-j+i-1]--;
                            left[i+j]--;
                        }
                    }
                }
            }
        }
        return ret;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<vector<int>> lamps={
        {2,5},{4,2},{0,3},{0,5},{1,4},{4,2},{3,3},{1,0}
    };
    vector<vector<int>> queries={
        {4,3},{3,1},{5,3},{0,5},{4,4},{3,3}
    };

    printArr( s.gridIllumination(6,lamps, queries));

    
}