#include "../s.h"



class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        

        int m = mat.size();
        int n = mat[0].size();
        k%=n;
        // if(n==1){
        //     return true;
        // }
        for(int i=0;i<n;i+=2){
            for(int j=0;j<m;j++){
                if(mat[j][i]!=mat[j][(i-k+n)%n]){
                    return false;
                }
                if(i+1<n){
                    if(mat[j][i+1]!=mat[j][(i+1+k)%n]){
                        return false;
                    }
                }
                
            }
        }



        
        return true;
  
    }
};

//[[9,1,8,9,2,9,1,8,9,2],[10,2,7,8,9,10,2,7,8,9],[7,6,6,9,5,7,6,6,9,5]]

int main(){

    Solution s;
    
}