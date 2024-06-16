#include "../s.h"

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        // sort(meetings.begin(), meetings.end());

        
        map<int, int> ct;
        for(auto &m: meetings){
            ct[m[0]]++;
            ct[m[1]]--;

        }
        int cur = 0;
        int ret = 0;
        int last_day=0;
        for(auto [day, diff]:ct){

            if(cur==0){
                ret += day-last_day-1;
            }
            last_day=day;
            cur+=diff;
        }

        if(cur==0){
            ret += days-last_day;
        }

        return ret;
        
  
    }
};