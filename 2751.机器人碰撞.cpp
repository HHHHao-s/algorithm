#include "s.h"
/*
 * @lc app=leetcode.cn id=2751 lang=cpp
 *
 * [2751] 机器人碰撞
 */

// @lc code=start
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        struct Node
        {
            int p,h;
            char d;
        };
        

        map<int, pair<int,char>> m;
        unordered_map<int, int> p2i;
        int i=0;
        for(int p: positions){

            m[p] = {healths[i],directions[i]};
            p2i[p] = i;
            i++;
        }
        list<Node> l;

        for(auto [p, pr]: m){

            l.push_back({p, pr.first, pr.second});

        }
        auto it = l.begin();
        while (1)
        {

            auto next = it;
            next++;
            if(next==l.end()){
                break;
            }
            if(next->d =='L' && it->d=='R'){
                if(next->h > it->h){
                    next->h--;
                    auto need_e = it;
                    if(it!=l.begin()){
                        it--;
                        l.erase(need_e);
                    }else{
                        l.erase(need_e);
                        it = l.begin();
                    }
                    
                    
                }else if(next->h == it->h){

                    auto need_e = it;
                    if(it!=l.begin()){
                        it--;
                        l.erase(need_e);
                        l.erase(next);
                        
                    }else{
                        l.erase(need_e);
                        l.erase(next);
                        it = l.begin();
                    }
                    
                    


                }else{
                    it->h--;
                    l.erase(next);
                }
            }else{
                it++;
            }
        }
        map<int,int> ir;

        for(auto [p, h,d] : l){
            ir[p2i[p]] = h;
        }
        vector<int> ret;
        for(auto [i, h]:ir){
            ret.push_back(h);
        }
        return ret;




    }
};
// @lc code=end

