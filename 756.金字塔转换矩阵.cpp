#include "s.h"
/*
 * @lc app=leetcode.cn id=756 lang=cpp
 *
 * [756] 金字塔转换矩阵
 */

// @lc code=start
class Solution {
private:

    unordered_map<string, vector<char>> m; 
    bool backTrace(string &cur ,string &next, int pos ){
        if(pos==cur.size()-1){
            if(next.size()==1){
                return true;
            }
            
            string new_s;
            new_s.reserve(6);
            return backTrace(next, new_s,0);
        }
        string s = {cur[pos],cur[pos+1]};
        auto &arr = m[s];
        for(auto it:arr){
            next.push_back(it);
            if(backTrace(cur,next,pos+1)){
                return true;
            }
            next.pop_back();
        }

        
        return false;

    }

public:
    bool pyramidTransition(string bottom,const vector<string>& allowed) {

        
        for(auto &s:allowed){
            m[s.substr(0,2)].push_back(s[2]);
        }

        string s;
        s.reserve(6);
        return backTrace(bottom,s, 0);


    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.pyramidTransition("AFFFFA",{"ADA","ADC","ADB","AEA","AEC","AEB","AFA","AFC","AFB","CDA","CDC","CDB","CEA","CEC","CEB","CFA","CFC","CFB","BDA","BDC","BDB","BEA","BEC","BEB","BFA","BFC","BFB","DAA","DAC","DAB","DCA","DCC","DCB","DBA","DBC","DBB","EAA","EAC","EAB","ECA","ECC","ECB","EBA","EBC","EBB","FAA","FAC","FAB","FCA","FCC","FCB","FBA","FBC","FBB","DDA","DDC","DDB","DEA","DEC","DEB","DFA","DFC","DFB","EDA","EDC","EDB","EEA","EEC","EEB","EFA","EFC","EFB","FDA","FDC","FDB","FEA","FEC","FEB","FFA","FFC","FFB","DDD","DDE","DDF","DED","DEE","DEF","DFD","DFE","DFF","EDD","EDE","EDF","EED","EEE","EEF","EFD","EFE","EFF","FDD","FDE","FDF","FED","FEE","FEF","FFD","FFE","FFF"});

}