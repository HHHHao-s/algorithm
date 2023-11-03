#include "s.h"
/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
// struct Comp
// {
//     bool operator()(const pair<int,int> &a, const pair<int,int> &b){
//         return a.first<=b.first;
//     }
// };


class FreqStack {
private:
    unordered_map<int,int> num_fre;
    map<int, stack<int>> freq_l;
    // priority_queue<pair<int,int>,vector<pair<int,int>>, Comp> p;

public:
    FreqStack() {

    }
    
    void push(int val) {
        num_fre[val]++;
        freq_l[num_fre[val]].push(val);
        
    }
    
    int pop() {
        
        auto &[freq, vals] = *freq_l.rbegin();
        int val = vals.top();
        vals.pop();
        num_fre[val]--;
        if(vals.size()==0){
            freq_l.erase(freq);
        }
        return val;

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

