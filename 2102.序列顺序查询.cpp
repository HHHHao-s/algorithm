#include "s.h"
/*
 * @lc app=leetcode.cn id=2102 lang=cpp
 *
 * [2102] 序列顺序查询
 */

// @lc code=start
class cmp1{
public:
    bool operator()(const pair<int, string>&a, const pair<int, string>&b){
        if(a.first<b.first)
            return true;
        else if(a.first==b.first)
            return a.second>b.second;
        else    
            return false;

    }

};

class cmp2{
public:
    bool operator()(const pair<int, string>&a, const pair<int, string>&b){
        if(a.first<b.first)
            return false;
        else if(a.first==b.first)
            return a.second<b.second;
        else    
            return true;

    }

};

class SORTracker {

    priority_queue<pair<int,string>,vector<pair<int,string>>, cmp1> pl;
    priority_queue<pair<int,string>,vector<pair<int,string>>, cmp2> pr;
    int cur=1;
public:
    SORTracker() {



    }
    
    void add(string name, int score) {

        pr.push({score, name});
        auto r = pr.top();
        pr.pop();
        pl.push(r);
    
    }

    
    string get() {

        auto l = pl.top();
        pl.pop();
        pr.push(l);
        return l.second;
        

    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
// @lc code=end

int main(){
    SORTracker tracker; // 初始化系统
    tracker.add("bradford", 2); // 添加 name="bradford" 且 score=2 的景点。
    tracker.add("branford", 3); // 添加 name="branford" 且 score=3 的景点。
    cout << tracker.get();              // 从好带坏的景点为：branford ，bradford 。
                                // 注意到 branford 比 bradford 好，因为它的 评分更高 (3 > 2) 。
                                // 这是第 1 次调用 get() ，所以返回最好的景点："branford" 。
    tracker.add("alps", 2);     // 添加 name="alps" 且 score=2 的景点。
    cout <<  tracker.get();              // 从好到坏的景点为：branford, alps, bradford 。
                                // 注意 alps 比 bradford 好，虽然它们评分相同，都为 2 。
                                // 这是因为 "alps" 字典序 比 "bradford" 小。
                                // 返回第 2 好的地点 "alps" ，因为当前为第 2 次调用 get() 。
    tracker.add("orland", 2);   // 添加 name="orland" 且 score=2 的景点。
    cout << tracker.get();              // 从好到坏的景点为：branford, alps, bradford, orland 。
                                // 返回 "bradford" ，因为当前为第 3 次调用 get() 。
    tracker.add("orlando", 3);  // 添加 name="orlando" 且 score=3 的景点。
    cout << tracker.get();              // 从好到坏的景点为：branford, orlando, alps, bradford, orland 。
                                // 返回 "bradford".
    tracker.add("alpine", 2);   // 添加 name="alpine" 且 score=2 的景点。
    cout << tracker.get();              // 从好到坏的景点为：branford, orlando, alpine, alps, bradford, orland 。
                                // 返回 "bradford" 。
    cout << tracker.get();              // 从好到坏的景点为：branford, orlando, alpine, alps, bradford, orland 。
                                // 返回 "orland" 。
}