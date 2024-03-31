#include "../s.h"


class Solution {
private:
    int getWithout(vector<vector<pair<int,int>>> p, int node){
        int mx = 0;
        for(int i=0;i<4;i++){
            if(p[i].front().second!=node && p[i].back().second!=node){
                mx = max(mx, p[i].back().first- p[i].front().first);
            }else if(p[i][0].second==node){
                mx = max(mx, p[i].back().first- p[i][1].first);
            }else if(p[i].back().second==node){
                mx = max(mx, p[i][p[i].size()-2].first-p[i][0].first);
            }
        }
        return mx;

    }

public:
    int minimumDistance(vector<vector<int>>& points) {
        
        vector<vector<pair<int,int>>> p(4);
        int n = points.size();
        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            p[0].push_back({x+y,i});
            p[1].push_back({-x+y,i});
            p[2].push_back({x-y,i});
            p[3].push_back({-x-y,i});
        }
        int mx=0;
        unordered_set<int> us;
        for(int i=0;i<4;i++){
            sort(p[i].begin(),p[i].end());
            if(mx<p[i][n-1].first-p[i][0].first){
                mx = p[i][n-1].first-p[i][0].first;
                us.clear();
            }
            if(mx==p[i][n-1].first-p[i][0].first){
                us.insert(p[i][n-1].second);
                us.insert( p[i][0].second);
            }
        }
        int ans = INT_MAX;
        for(auto x: us){
            cout << x << endl;
            ans = min(getWithout(p, x), ans);
        }
        return ans;

    }
};


int main(){
    
}