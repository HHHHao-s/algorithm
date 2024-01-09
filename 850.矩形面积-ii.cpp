#include "s.h"
/*
 * @lc app=leetcode.cn id=850 lang=cpp
 *
 * [850] 矩形面积 II
 */

// @lc code=start
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {

        vector<int> hbound;
        for(auto &rec: rectangles){
            hbound.push_back(rec[1]);
            hbound.push_back(rec[3]);
        }
        sort(hbound.begin(),hbound.end());
        hbound.erase(unique(hbound.begin(), hbound.end()),hbound.end());
        int m  =hbound.size();
        struct Info{
            int x;
            int index;
            int diff;
        };
        vector<Info> infos;
        for(int i = 0;i<rectangles.size(); i++){
            auto &rec = rectangles[i];
            infos.push_back({rec[0], i, 1});
            infos.push_back({rec[2], i, -1});
        }
        sort(infos.begin(), infos.end(), [](const Info&a, const Info& b){
            return a.x<b.x;
        });

        vector<int> seg(m);
        long long ans= 0;
        for(int i=0;i<infos.size();i++){

            
            int j = i;
            while(j+1<infos.size() && infos[j+1].x==infos[i].x){
                j++;
            }
            if(j+1==infos.size()){
                break;
            }

            for(int k=i;k<=j;k++){
                auto [tx,index, diff] = infos[k];
                int down = rectangles[index][1];
                int up = rectangles[index][3];

                for(int x=0;x<m-1;x++){
                    if(down<=hbound[x] && up>=hbound[x+1]){
                        seg[x]+=diff;
                    }
                }
            }
            int cover=0;

            for(int x=0;x<m-1;x++){
                if(seg[x]>0){
                    cover+= hbound[x+1]-hbound[x];
                }
            }
            ans += ((long long)cover) * (infos[j+1].x-infos[j].x);
            i=j;



        }
        return (ans % (long long)(1e9+7));

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> rec={
        {0,0,2,2},
        {1,0,2,3},
        {1,0,3,1}
    };
    cout<< s.rectangleArea(rec);
}