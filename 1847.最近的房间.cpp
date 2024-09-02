#include "s.h"
/*
 * @lc app=leetcode.cn id=1847 lang=cpp
 *
 * [1847] 最近的房间
 */

// @lc code=start
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {

        vector<pair<int,int>> rom;
        vector<tuple<int,int,int>> qs;

        for(const auto&room: rooms){
            rom.push_back({room[1], room[0]});
        }
        for(const auto &q: queries){
            qs.push_back({q[1], q[0], qs.size()});
        }

        sort(rom.begin(), rom.end(), greater<>());
        sort(qs.begin(), qs.end(), greater<>());
        set<int> have;
        int j= 0;
        int i=0;
        vector<int> ret(qs.size());
        for(;j<qs.size();j++){

            auto [need, prefer, index] = qs[j];
            while(i<rom.size() && rom[i].first >= need){
                have.insert(rom[i].second);
                i++;
            } 
            if(have.empty()){
                ret[index] = -1;
                continue;
            }
            auto it = have.lower_bound(prefer);
            if(it==have.end()){
                --it;
                ret[index] = *it; 
            }else{
               
                if(it!=have.begin()){
                    int r = *it - prefer;
                    --it;
                    int l = prefer- *it ;
                    if(l<=r){
                        ret[index] = *it;

                    }else{
                        ++it;
                        ret[index] = *it; 
                    }
                }else{
                    ret[index] = *it;
                }
                
            }

        }
        return ret;

    }
};
// @lc code=end

int main(){


    Solution s;
    vector<vector<int>> rooms={{1,4},{2,3},{3,5},{4,1},{5,2}}, qs={{2,3},{2,4},{2,5}} ;
    
    printArr(s.closestRoom(rooms, qs));
}