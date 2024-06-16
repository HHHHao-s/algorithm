#include "../s.h"


class Solution {


public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {

        function<long long(int ,int ,int ,int ,int ,int ,int ,int)> f = [&](int x1,int y1, int x2, int y2, int x3, int y3, int x4 , int y4){

            long long ans;

            if(x1<x3 && y1<y3){
                if(x2<=x3 || y2<=y3){
                    ans = 0ll;
                }else{
                    long long mx = min(x4-x3, x2-x3);
                    long long my = min(y4-y3, y2-y3);
                    ans = min(mx, my)*min(mx, my);
                }
            }else if(x3<x1 && y3<y1){

                ans = f(x3,y3,x4,y4,x1,y1,x2,y2);
            }else if(x1<x3 && y1>y3){
                if(x2<=x3 || y4<=y1){
                    ans = 0ll;
                }else{
                    long long mx = min(x4-x3, x2-x3);
                    long long my = min(y4-y1, y2-y1);
                    ans = min(mx, my)*min(mx, my);
                }
            }else if(x1>x3&&y1<y3){
                ans = f(x3,y3,x4,y4,x1,y1,x2,y2);
            }else if(x1==x3 && y1<=y3){
                if(y2 <= y3){
                    ans = 0ll;
                }else{
                    long long mx = min(x4-x1, x2-x1);
                    long long my = min(y2-y3, y4-y3);
                    ans = min(mx, my)*min(mx, my);
                }
            }else if(x1==x3 && y1>y3){
                ans = f(x3,y3,x4,y4,x1,y1,x2,y2);
            }else if(y1==y3 && x1<=x3){
                if(x2<=x3){
                    ans = 0ll;
                }else{
                    long long mx = min(x4-x3, x2-x3);
                    long long my = min(y2-y1, y4-y1);
                    ans = min(mx, my)*min(mx, my);
                }
            }else if(y1==y3 && x1>x3){
                ans = f(x3,y3,x4,y4,x1,y1,x2,y2);
            }

            return ans;

        }; 

        int n = bottomLeft.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                ans = max(ans, f(bottomLeft[i][0], bottomLeft[i][1], topRight[i][0],topRight[i][1],
                bottomLeft[j][0],bottomLeft[j][1],topRight[j][0], topRight[j][1]));
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> a = {{1,1},{2,2},{3,1}};
    vector<vector<int>> b = {{3,3},{4,4},{6,6}};

    cout << s.largestSquareArea(a,b);
}