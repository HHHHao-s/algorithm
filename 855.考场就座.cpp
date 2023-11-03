#include "s.h"
/*
 * @lc app=leetcode.cn id=855 lang=cpp
 *
 * [855] 考场就座
 */

// @lc code=start
class ExamRoom {
private:
    set<int> seats;
    int n;
public:
    ExamRoom(int _n) {
        n = _n;


    }
    
    int seat() {

        if(seats.empty()){
            seats.insert(0);
            return 0;
        }
        auto it= seats.begin();
        auto it2 = ++seats.begin();
        if(it2==seats.end()){
            
            int ret= (*it)> (n-*it)?0:n-1;
            seats.insert(ret);
            return ret;
        }
        int max_dis = *it;
        int ret = 0;


        while(it2!=seats.end()){
            if((*it2-*it)/2>max_dis){
                max_dis = (*it2-*it)/2;
                ret = *it+max_dis;
            }
            it++;
            it2++;
        }
        if(n-1-*it>max_dis){
            ret = n-1;
        }

        seats.insert(ret);
        return ret;
    }
    
    void leave(int p) {

        seats.erase(p);

    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

