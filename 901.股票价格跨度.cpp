#include "s.h"
/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
private:
    stack<pair<int,int>> st;
    int cur_pos = 1;
public:
    StockSpanner() {

        st.push({10000000,0});
    }
    
    int next(int price) {
        
        while(st.top().first<=price){
            st.pop();
        }
        int last = st.top().second;
        int pos = cur_pos++;
        st.push({price,pos});
        return pos-last;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

