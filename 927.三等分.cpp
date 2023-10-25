#include "s.h"
/*
 * @lc app=leetcode.cn id=927 lang=cpp
 *
 * [927] 三等分
 */

// @lc code=start
class Solution {
public:
    vector<int> threeEqualParts(const vector<int>& arr) {
        int n = arr.size();
        int ones=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                ones++;
            }
        }

        if(ones%3!=0){
            return {-1,-1};
        }
        if(ones==0){
            return{0,2};
        }
        int cnt=0;
        int pos_i=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                cnt++;
                pos_i = i;
                if(cnt==ones/3){
                    break;
                }
            }
        }
        int cnt2 = 0;
        int pos_j=0;
        int back_zero=0;
        for(int i =n;i-->0;){
            
            if(arr[i]==1){
                cnt2++;
                if(cnt2==ones/3){
                    pos_j = i;
                    break;
                }
            }else{
                if(cnt2==0){
                    back_zero++;
                }
            }
        }
        int reti= pos_i+back_zero;
        for(int i=pos_j-1;i>=pos_j-back_zero;i--){
            if(arr[i]==1){
                // 这一段一定要是0
                return {-1,-1};
            }
        }
        int retj=0;
        for(int i=pos_j;i-back_zero-1>=0;i--){
            if(arr[i-back_zero-1]==1){  
                retj = i;
                break;
            }
        }
        int p1=0,p2=reti+1,p3=retj;
        while(arr[p1]==0){
            p1++;
        }
        while(arr[p2]==0){
            p2++;
        }
        while(arr[p3]==0){
            p3++;
        }


        for(;p3<n ;p1++,p2++,p3++){
            if(arr[p1]==arr[p2] && arr[p2]==arr[p3]){
                continue;
            }else{
                return {-1,-1};
            }


        }

        return {reti, retj};


    }
};
// @lc code=end

int main(){

    Solution s;

    printArr(s.threeEqualParts({1,0,1,0,1,0,0,0,0,0}));
    
}