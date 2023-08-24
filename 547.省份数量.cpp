#include "s.h"
/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:

    vector<int> bc;

    int find(int x){
        return x==bc[x]?x:bc[x]=find(bc[x]);
    }

    void merge(int x, int y){
        bc[find(x)] = find(y);
    }


    int findCircleNum(const vector<vector<int>>& isConnected) {

        int n =isConnected.size();

        bc = vector<int>(n);
        for (int i = 0; i < n; i++) {
            bc[i] = i;
        }

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]){
                    merge(i,j);
                }
                for(int k=0;k<n;k++){
                    if(isConnected[i][j]==1 && isConnected[k][j]==1){
                        merge(i,k);
                        
                    }
                }
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(bc[i]==i){
                ans++;
            }
        }

        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.findCircleNum({
        {1,0,1},
        {0,1,1},
        {1,1,1}
        
    });

    return 0;
}