#include "s.h"
/*
 * @lc app=leetcode.cn id=1912 lang=cpp
 *
 * [1912] 设计电影租借系统
 */

// @lc code=start
class MovieRentingSystem {
public:

    unordered_map<int, map<int,set<int>>> s;
    unordered_map<int, unordered_map<int, int>> sp;

    map<int, map<int,set<int>>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {

        for(auto &e:entries){
            s[e[1]][e[2]].insert(e[0]);
            sp[e[1]][e[0]] = e[2];
        }



    }
    
    vector<int> search(int movie) {
        auto & mp = s[movie];
        vector<int> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            for(auto it2=it->second.begin(); it2!=it->second.end();it2++){
                ans.push_back(*it2);
                if(ans.size()==5){
                    return ans;
                }
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = sp[movie][shop];
        s[movie][price].erase(shop);
        rented[price][shop].insert(movie);

    }
    
    void drop(int shop, int movie) {
        int price = sp[movie][shop];
        s[movie][price].insert(shop);
        rented[price][shop].erase(movie);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ret;
        for(auto it=rented.begin();it!=rented.end();it++){
            for( auto it2=it->second.begin();it2!=it->second.end();it2++){
                for(auto it3=it2->second.begin();it3!=it2->second.end();it3++){
                    ret.push_back({it2->first, *it3});
                    if(ret.size()==5){
                        return ret;
                    }
                }
            }
        }
        return ret;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
// @lc code=end

