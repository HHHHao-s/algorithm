#include "../s.h"

class Solution {
public:
    int minGroupsForValidAssignment(const vector<int>& nums) {
        
        unordered_map<int, int> num_cnt;
        int min_cnt=INT_MAX;
        for(int num: nums){
            num_cnt[num]++;            
        }
        for(auto [x, cnt]:num_cnt){
            min_cnt = min(cnt, min_cnt);
        }

        int low = 1;
        int high = min_cnt;
        int ans = INT_MAX;
        for(int mid=high;mid>=1;mid--){

            int flag = 0;
            int tmp_ans=0;
            for(auto [x, cnt]:num_cnt){
                if(cnt%(mid+1)!=0){
                    if(cnt/(mid+1)+cnt%(mid+1)<mid){
                        flag=-1;
                        break;  
                    }
                }
                
                tmp_ans += (cnt+mid)/(mid+1);
            }
            if(flag==-1){
                high = mid-1;
            }else if(flag==0){
                ans = min(tmp_ans, ans);
                low = mid+1;
            }
        }
        return ans;


    }
};

int main(){

    Solution s;
    cout << s.minGroupsForValidAssignment({1,1,1,1,1});
    cout << s.minGroupsForValidAssignment({1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2});


    return 0;
}