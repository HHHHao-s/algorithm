#include "../s.h"

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

        unordered_map<string, vector<int>> m;

        auto f=[&](string &time){
            return 60*(10*(time[0]-'0')+time[1]-'0') + 10*(time[2]-'0')+time[3]-'0';
        };

        for(auto &vec:access_times){
            m[vec[0]].push_back(f(vec[1]));
        }

        

        vector<string> ans;
        for(auto& [men, acct]: m){
            if(acct.size()<3){
                continue;
            }
            sort(acct.begin(),acct.end());
            auto p = acct.begin();
            int next=2;
            while(next<acct.size()){
                auto p0 = p;
                auto p1 = ++p0;
                auto p2 = ++p0;
                if(*p2-*p<60){
                    ans.push_back(men);
                    break;
                }
                next++;
                p++;

            }


        }
        return ans;

    }
};