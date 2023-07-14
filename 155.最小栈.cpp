#include "s.h"
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:

    long cur_min=0;
    stack<long> st{};

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            
            cur_min = val;
           
            st.push(0);
            
            
        }else{
            long diff = val - cur_min;
            st.push(diff);
            cur_min = diff<0?val:cur_min;
        }
    }
    
    void pop() {
        long diff = st.top();
        st.pop();
        if(diff<0){
            cur_min-=diff;
        }


    }
    
    int top() {
        long diff = st.top();
        if(diff<0){
            return cur_min;
        }else{
            return cur_min+diff;
        }
        
    }
    
    int getMin() {
        return cur_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

