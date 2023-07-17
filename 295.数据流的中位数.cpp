#include "s.h"
/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:

    priority_queue<int> q1;
    priority_queue<int,vector<int>, greater<int>> q2;
    double cur=0;



    MedianFinder():q2(greater<int>()) {


    }
    
    void addNum(int num) {

        if(q1.empty() && q2.empty()){
            q1.push(num);
        }else{
            if(q1.size()>q2.size()){     
                q1.push(num);             
                q2.push(q1.top());
                q1.pop();
            }else{
                q2.push(num);
                q1.push(q2.top());
                q2.pop();
            }       
        }
    }
    
    double findMedian() {
        if(q1.size()>q2.size()){
            return q1.top();
        }else{
            return (1.0*(q1.top()+q2.top()))/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end


int main(){

    MedianFinder obj;
    vector<int> testcase = {-1,-2,-3,-4,-5};
    for(int i=0;i<testcase.size();i++){
        obj.addNum(testcase[i]);
        cout << obj.findMedian() << endl;
    }


    return 0;
}
