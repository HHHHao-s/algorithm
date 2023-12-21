#include "s.h"
/*
 * @lc app=leetcode.cn id=1453 lang=cpp
 *
 * [1453] 圆形靶内的最大飞镖数量
 */

// @lc code=start
struct Point{
    double x,y;
};

class Solution {
private:
    const double eps = 1e-8;
    double dis(Point a, Point b){
        
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }

    double cdir(Point a, Point b){
        return (a.y-b.y)/(a.x-b.x);
    }

    Point cmid(Point a, Point b){
        return (Point){.x=(a.x+b.x)/2, .y=(a.y+b.y)/2};
    }

    int dcmp(double x) {
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}



public:
    int numPoints(vector<vector<int>>& darts, int ir) {
        int n = darts.size();
        int ans = 1;
        double r= ir;
        for(int i=0;i<n;i++){
            Point a = {(double)darts[i][0], (double)darts[i][1]};
            for(int j=0;j<n;j++){
                Point b = {(double)darts[j][0], (double)darts[j][1]};
                if(i==j || dis(a,b)>2*r){
                    continue;
                }
                Point mid = cmid(a, b);
                double mid_dis = dis(mid, a);
               
                double d = sqrt(r*r- mid_dis*mid_dis);
                Point dir = (Point){.x=a.y-b.y, .y=b.x-a.x};
                double px = d*dir.x/sqrt(dir.x*dir.x+dir.y*dir.y) + mid.x;
                double py = d*dir.y/sqrt(dir.x*dir.x+dir.y*dir.y) + mid.y;
                Point p={px,py};
                int cnt = 0;
                for(int g=0;g<n;g++){
                    // if(g==i || g==j){
                    //     continue;
                    // }
                    Point c = {(double)darts[g][0], (double)darts[g][1]};
                    double ds = dis(p,c);
                    if(dcmp(ds-ir)<=0){
                        cnt++;
                        
                    }
                }
                ans = max(ans, cnt);
                
                
            }
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> darts={
        {-3,0},{3,0},{2,6},{5,4},{0,9},{7,8}
    };
    cout << s.numPoints(darts, 5);
}