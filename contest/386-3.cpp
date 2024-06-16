#include "../s.h"

class Solution {


public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();

        long long acc = accumulate(nums.begin(), nums.end(), 0ll);
        
        if(acc+n>m){
            return -1;
        }



        auto check = [&](int s){
            vector<int> last(n, -1);

            for(int i=0;i<s;i++){
                int x = changeIndices[i]-1;
                last[x] = i;
            }

            for(int i=0;i<n;i++){
                if(last[i]==-1){
                    return 0;
                }
            }
            int have = 0;
            for(int i=0;i<m;i++){
                if(i == last[changeIndices[i]-1]){
                    
                    have-=nums[changeIndices[i]-1];
                    if(have<0){
                        return 0;
                    }
                    
                }else{
                    have++;
                }

            }
            return 1;
        };
        if(!check(m)){
            return -1;
        }

        int l=n, r=m-1;

        while(l<=r){
            int mid = (l+r)/2;

            if(check(mid)){
                r = mid-1;
            }else{
                l = mid+1;
            }

        }
        return r+1;

    }
};

int main(){
    Solution s;
    vector<int> a = {2,2,0}, b={2,2,2,2,3,2,2,1};
    cout << s.earliestSecondToMarkIndices(a,b);
}