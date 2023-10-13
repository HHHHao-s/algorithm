#include "s.h"
/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 *
 * [1488] 避免洪水泛滥
 */

// @lc code=start
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n =rains.size();
        unordered_set<int> lake;
        
        int lakes=0;
        int release=0;
        
        unordered_map<int, deque<int>> lake2queue;
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                release++;
                continue;
            }
            if(lake.count(rains[i])==0){
                lakes++;      
                lake.insert(rains[i]);  
                    
            }else{
                lake2queue[rains[i]].push_back(i);
            }
            
            
        }
        vector<int> ans(n,-1);
        
        if(release< n-release-lakes){
            return {};
        }
        
        map<int,int> m;

        lake.clear();
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                if(!m.empty()){
                    auto fir = m.begin();
                    ans[i] = fir->second;
                    lake.erase(fir->second);
                    m.erase(fir->first);
                }else{
                    ans[i] = 1;
                }
                

                continue;
            }
            if(lake.count(rains[i])==0){
                //set full
                lake.insert(rains[i]);
                if(!lake2queue[rains[i]].empty()){
                    m[lake2queue[rains[i]].front()] = rains[i];
                    lake2queue[rains[i]].pop_front();
                }
                
            }else if(lake.count(rains[i])==1){
                return {};
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> rains={
        1,0,2,0
    };
    printArr(s.avoidFlood(rains));

    return 0;
}