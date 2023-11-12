#include "../s.h"

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        // function<void()> f=[&](){

        // };

        // no change
        int mx1 = nums1[n-1];
        int mx2 = nums2[n-1];
        int cnt = 0;
        for(int i=0;i<n-1;i++){
            if(nums1[i]<=mx1 && nums2[i]<=mx2 ){
                continue;
            }else if(nums1[i]<=mx2 && nums2[i]<=mx1){
                cnt++;
            }else {
                cnt=-1;
                break;
            }
        }
        
        swap(mx1,mx2);
        int cnt2=1;
        for(int i=0;i<n-1;i++){
            if(nums1[i]<=mx1 && nums2[i]<=mx2 ){
                continue;
            }else if(nums1[i]<=mx2 && nums2[i]<=mx1){
                cnt2++;
            }else {
                cnt2=-1;
                break;
            }
        }
        if(cnt==-1 && cnt2==-1){
            return -1;
        }else if(cnt==-1 && cnt2!=-1){
            return cnt2;

        }else if(cnt2==-1 && cnt!=-1){
            return cnt;
        }else {
            return min(cnt,cnt2);
        }


    }
};

int main(){
    Solution s;
    vector<int> v1 = {1,2,7},v2={4,5,3};

    cout <<s.minOperations(v1,v2);
}