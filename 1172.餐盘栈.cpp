#include "s.h"
/*
 * @lc app=leetcode.cn id=1172 lang=cpp
 *
 * [1172] 餐盘栈
 */

// @lc code=start
class DinnerPlates {
private:
    vector<stack<int>> stacks;
    int capacity;
    int right{-1};
    set<int> pq; 

public:
    DinnerPlates(int cap) {
        capacity = cap;

    }
    
    void push(int val) {
        if(pq.empty()){
            if(right==-1 || stacks[right].size()==capacity){
                stacks.push_back({});
                
                right++;
                stacks[right].push(val);
                return;
            }else{
                
                stacks[right].push(val);
               
            }
            
        }else{
            int index = *pq.begin();           
            stacks[index].push(val);
            if(stacks[index].size()==capacity){
                pq.erase(index);
            }
        }
    }
    
    int pop() {
        if(right==-1){
            cout << -1 << endl;
            return -1;
        }
        int val = stacks[right].top();
        stacks[right].pop();
        while(right>=0 && stacks[right].empty()){
            right--;
            stacks.pop_back();
            pq.erase(right);
            
        }
        cout << val << endl;
        return val;
        
    }
    
    int popAtStack(int index) {
        if(index==right){
            int val = pop();
            cout << val << endl;
            return val;
        }else if(index>right){
            return -1;
        }else{
            if(stacks[index].empty()){
                return -1;
            }else{
                int val = stacks[index].top();
                stacks[index].pop();
                pq.insert(index);
                return val;
                cout << val << endl;
            }
        }
        return -1;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// @lc code=end



int main(){

    DinnerPlates dinner(1);
    dinner.push(1);
    dinner.push(2);
    dinner.push(3);
    dinner.popAtStack(0);
    dinner.pop();
    dinner.pop();
    dinner.push(1);
    dinner.push(2);
    
}
