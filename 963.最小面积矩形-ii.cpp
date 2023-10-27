#include "s.h"
/*
 * @lc app=leetcode.cn id=963 lang=cpp
 *
 * [963] 最小面积矩形 II
 */

// @lc code=start
class Comp{
public:
    bool operator()(const pair<int,int>& a, const pair<int,int>& b)const{
        return pow(a.first,2)+pow(a.second,2)<pow(b.first,2)+pow(b.second,2);
    }
};
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
    double minAreaFreeRect(vector<vector<int>>& points) {

        
        unordered_map<pair<int,int>,set<pair<int,int>, Comp>, pair_hash> vec_point;

        int n = points.size();
        for(int i=0;i<n;i++){
            auto& point1 = points[i];
            int x1=point1[0];
            int y1=point1[1];
            for(int j=0;j<n;j++){
                auto& point2 = points[j];
                int x2=point2[0];
                int y2=point2[1];
                if(x1==x2&&y1==y2) continue;
                int diffx = x1-x2;
                int diffy = y1-y2;
                if(diffx<0){
                    diffx=-diffx;
                    diffy=-diffy;
                }
                // cout << diffx << " " << diffy << endl;
                if(x1-x2<0){
                    vec_point[{diffx,diffy}].insert({x1,y1});
                }else{
                    vec_point[{diffx,diffy}].insert({x2,y2});
                }
                
            }
        }
        double ans = 1600000000;

        for(auto& [vec, points]: vec_point){
            // cout << vec.first << " " << vec.second << endl;
            int k = points.size();
            auto it = points.begin();
            auto it2 = it;
            it2++;
            for(int i=0;i<k-1;i++){
                
                
                int x1 = it->first;
                int y1 = it->second;
                int x2 = it2->first;
                int y2 = it2->second;
                if((x2-x1)*vec.first + (y2-y1)*vec.second==0){
                    ans = min(ans,sqrt(pow(x2-x1,2)+pow(y2-y1,2))*sqrt(pow(vec.first,2)+pow(vec.second,2))); 
                }
                it++;
                it2++;
            }
        }
        return ans==1600000000?0:ans;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<vector<int>> points = {{3,1},{1,1},{0,1},{2,1},{3,3},{3,2},{0,2},{2,3}};
    cout<<s.minAreaFreeRect(points)<<endl;
    // vector<vector<int>> points = {{1,2},{2,1},{1,0},{0,1}};
    // cout<<s.minAreaFreeRect(points)<<endl;
    return 0;
}