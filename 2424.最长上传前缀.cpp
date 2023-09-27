#include "s.h"
/*
 * @lc app=leetcode.cn id=2424 lang=cpp
 *
 * [2424] 最长上传前缀
 */

// @lc code=start
class LUPrefix {
    set<int> st;
public:
    LUPrefix(int n) {
        for (int i = 1; i <= n + 1; i++) {
            st.insert(i);
        }
    }

    void upload(int video) {
        st.erase(video);
    }

    int longest() {
        return *st.begin() - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
// @lc code=end

int main(){

    LUPrefix l(40);
    l.upload(3);
    cout << l.longest();
    l.upload(10);
    l.upload(20);
    l.upload(15);
    l.upload(30);
    l.upload(17);
    l.upload(16);
    l.upload(19);

    
    

    return 0;
}