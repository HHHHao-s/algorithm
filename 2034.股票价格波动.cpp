#include "s.h"
/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

// @lc code=start
class StockPrice {
private:
    unordered_map<int,int> t2p;
    map<int,int> p_set;// 记录排好序的price个数
    int cur;

public:
    StockPrice() {
        cur = 0;
    }
    
    void update(int timestamp, int price) {
        if(t2p.count(timestamp)==0){
            t2p[timestamp] = price;
            p_set[price]++;
            if(timestamp>cur){
                cur = timestamp;
            }
        }else{
            p_set[t2p[timestamp]]--;
            if(p_set[t2p[timestamp]]==0){
                p_set.erase(t2p[timestamp]);
            }
            t2p[timestamp] = price;
            p_set[price]++;
        }
    }
    
    int current() {
        return t2p[cur];
    }
    
    int maximum() {
        return p_set.rbegin()->first;
    }
    
    int minimum() {
        return p_set.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

