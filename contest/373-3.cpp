#include "../s.h"


// struct UnionFind{
//     UnionFind(size_t n): arr(n){
//         for(int i=0;i<n;i++){
//             arr[i] = {i,1};
//         }
//     }

//     int Find(int x){
//         return arr[x].fa==x?x:(arr[x].fa=Find(arr[x].fa));
//     }
//     void Union(int x, int y){
//         int fax = Find(x);
//         int fay = Find(y);
//         if(fax!=fay){
//             arr[fax].cnt += arr[fay].cnt;
//             arr[fay].fa = fax;
//         }
//     }
//     int& GetCnt(int x){
//         return arr[Find(x)].cnt;
//     }

//     struct Info{
//         int fa,cnt,index;
//     };
//     vector<Info>  arr;
// };

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        vector<int> ans(nums.size());
        vector<pair<int,int>> tmp;
        for(int i=0;i<nums.size();i++){
            tmp.push_back({nums[i],i});
        }
        auto cmp = [](const pair<int,int>&a ,const pair<int,int>&b){
            return a.first<b.first;
        };
        sort(tmp.begin(),tmp.end(), cmp);
        int i=0;
        for(;i<tmp.size();){
            priority_queue<int,vector<int>, greater<int>> pq;
            pq.push(tmp[i].second);
            int j = i;
            i++;
            while(i<tmp.size() && tmp[i].first<=tmp[i-1].first+limit){
                pq.push(tmp[i].second);
                i++;
            }
            
            while(!pq.empty()){
                int fir = pq.top();
                pq.pop();
                ans[fir]=tmp[j++].first;
            }        
        }
        return ans;
    }
};