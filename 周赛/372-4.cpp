#include "../s.h"

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        
        int qn = queries.size();
        vector<int> ans(qn, -1);
        int index= 0;
        vector<map<int, vector<int>>> new_q(heights.size());
        
        for(auto &pr: queries){
            if(pr[0]>pr[1]){
                swap(pr[0], pr[1]);
            }
            if(pr[0]==pr[1] || heights[pr[0]]<heights[pr[1]]){
                ans[index] = pr[1];
            }else{
                new_q[pr[1]][heights[pr[0]]].push_back(index);
            }
            index++;
        }
        
        deque<pair<int,int>> st;


        for(int j=heights.size()-1;j>=0;--j){
            if(new_q[j].empty()){
                while(!st.empty() && st.front().first<=heights[j]){
                
                    st.pop_front();
                }
                st.push_front({heights[j],j});
                continue;
            }
            deque<pair<int,int>> tmp_st=st;
            for(auto &[ih, indexs]: new_q[j]){
                while(!st.empty() && st.front().first<ih){
                    
                    st.pop_front();
                }
                if(st.empty()){
                    for(auto index: indexs){
                        ans[index] = -1;
                    }

                }else{
                    for(auto index: indexs){
                        ans[index] = st.front().second;
                    }
                }
                
            }
            st = move(tmp_st);
            while(!st.empty() && st.front().first<heights[j]){
                
                st.pop_front();
            }
            st.push_front({heights[j],j});
           
        }
        return ans;

    }
};

int main(){
    Solution s;
    vector<int> heights={
        6,4,8,5,2,7
    };
    vector<vector<int>> queries={
        {0,1},{0,3},{2,4},{3,4},{2,2}
    };
    printArr(s.leftmostBuildingQueries(heights, queries));
}