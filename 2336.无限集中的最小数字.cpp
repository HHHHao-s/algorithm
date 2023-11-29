#include "s.h"
/*
 * @lc app=leetcode.cn id=2336 lang=cpp
 *
 * [2336] 无限集中的最小数字
 */

// @lc code=start
class SmallestInfiniteSet {
private:
    int level{1};
    set<int> s;
public:
    SmallestInfiniteSet() {

    }
    
    int popSmallest() {
        if(!s.empty()){
            int ret = *s.begin();
            s.erase(ret);
            return ret;
        }else{
            return level++;
        }
    }
    
    void addBack(int num) {
        if(num<level){
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

