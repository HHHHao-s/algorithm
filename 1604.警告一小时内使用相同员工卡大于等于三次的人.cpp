#include "s.h"
/*
 * @lc app=leetcode.cn id=1604 lang=cpp
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

// @lc code=start
class Solution {
private:
    int get_time(const string& time){
        return ((time[0]-'0')*10+(time[1]-'0'))*60 + (time[2]-'0')*10 + time[3]-'0';
    }

public:
    vector<string> alertNames(const vector<string>& keyName, const vector<string>& keyTime) {
        set<string> ans;

        unordered_map<string, vector<int>> m;

        for(int i=0;i<keyName.size();i++){
            const string &name = keyName[i];
            int time = get_time(keyTime[i]);
            if(ans.count(name)){
                continue;
            }

            if(m.count(name)==0){
                m[name] = {time};
            }else{
                auto it = lower_bound(m[name].begin(), m[name].end(), time);
                if(it!=m[name].end() && it!=m[name].begin() ){
                    if( time - *(it-1)<60 && m[name].size()>=2){
                        ans.insert(name);
                    }else{
                        m[name].insert(it ,time);
                    }
                    
                }else if(it==m[name].end()  && m[name].size()>=2){
                    auto end = m[name].rbegin();
                    if(time - *(end-1)<60){
                        ans.insert(name);
                    }else{
                        m[name].insert(it ,time);
                    }
                }else if(it==m[name].begin()&& m[name].size()>=2){
                    auto begin = m[name].begin();
                    if(*(begin+1)-time<60){
                        ans.insert(name);
                    }else{
                        m[name].insert(it ,time);
                    }
                }else{
                    m[name].insert(it ,time);
                }
                
            }
        }

        vector<string> ret;
        for(auto each :ans){
            ret.push_back(each);
        }
        return ret;
    }
};
// @lc code=end

int main(){

    Solution s;
    s.alertNames(
        {"daniel","daniel","daniel","luis","luis","luis","luis"},
        {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"}
    );


    return 0;
}