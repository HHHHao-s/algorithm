#include "s.h"
/*
 * @lc app=leetcode.cn id=853 lang=cpp
 *
 * [853] 车队
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        map<int, int> ps_speed;
        int n = position.size();
        for(int i=0;i<n;i++){
            ps_speed[position[i]] = speed[i];
        }


        int ret = 0;

        for(auto it = ps_speed.rbegin();it!=ps_speed.rend();){

            long long last = target-it->first;
            long long sp1 = it->second;
            ret ++;
            auto it2 = it;
            it2++;
            for(;it2!=ps_speed.rend();it2++){
                
                long long last2 = target-it2->first;
                long long sp2 = it->second;

                long long diff = it->first - it2->first;
                
                long long sp_diff = it2->second - it->second;
                if(sp_diff <0 || last * sp_diff < diff*sp1){
                    
                    break;
                }
            }
            it = it2;
           

            

        }

        return ret;


    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int >p= {0,2,4};
    vector<int> sp= {4,2,1};
    cout <<s.carFleet(100,p,sp);
}