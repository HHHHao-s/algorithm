#include "s.h"
/*
 * @lc app=leetcode.cn id=835 lang=cpp
 *
 * [835] 图像重叠
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> shrink(vector<vector<int>>& img){
        int n = img.size();
        int i=0;
        for(;i<n;i++){
            int j=i;
            for(;j<n;j++){
                if(img[i][j]==1 || img[j][i]==1){
                    break;
                }
            }
            if(j!=n){
                break;
            }
        }
        if(i==n){
            return vector<vector<int>>{{0}};
        }
        int off = i;
        vector<vector<int>> ret(n-i,vector<int>(n-i));
        
        for(;i<n;i++){
            
            for(int j=off;j<n;j++){
                ret[i-off][j-off] = img[i][j];
            }

        }
        
        return ret;
    

    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        img1 = std::move(shrink(img1));
        img2 = std::move(shrink(img2));

        int m = img1.size();
        int n = img2.size();
        int ans = 0;
        if(m<n){
            swap(img1, img2);
            swap(m,n);
        }
        
        for(int i=0;i<m+n-1;i++){
            for(int j=0;j<m+n-1;j++){
                int tmp_sum=0;
                for(int k=n-1;k>=0;k--){
                    for(int l=n-1;l>=0;l--){
                        // cout << j-(n-l-1) << ' ' <<  i-(n-k-1) << endl;
                        if(j-(n-l-1)>=0 && i-(n-k-1)>=0 && j-(n-l-1)<m && i-(n-k-1)<m){
                            tmp_sum+=img1[i-(n-k-1)][j-(n-l-1)] & img2[k][l];
                        }   
                    }
                }
                ans = max(tmp_sum, ans);
            }
        }
            

        
        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<vector<int>> img1={
        {0,0,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,0,1},
        {0,1,0,0,1}
    };
    vector<vector<int>> img2={
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {0,1,1,1,1},
        {1,0,1,1,1}
  
    };

    cout << s.largestOverlap(img1,img2);
    
}