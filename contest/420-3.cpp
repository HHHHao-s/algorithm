#include "../s.h"
vector<int> prime;
unordered_set<int> is_prime;
    
vector<int> nxt;
auto init = []{

    vector<int> can(1000001,1);
    nxt.assign(1000001,0);
    for(int i=2;i<1001;i++){
        for(int j=i*i;j<1000001;j+=i){
            if(can[j]){
                nxt[j] = i;
            }
            can[j] = 0;
            

        }
    }
    
    for(int i=2;i<1000001;i++){
        if(can[i]){
            nxt[i] = i;
        }
    }
    return 0;

}();

class Solution {
public:


    int minOperations(vector<int>& nums) {
        
        

        int n = nums.size();
        
        int last1=0;
        int last2=1;
        int last=nums[0];


        for(int i=1;i<n;i++){
            
            int num = nums[i];
            int nnum = nxt[num];
            int lastnum = nums[i-1];
            int cur1,cur2;
            if(num>=lastnum && last1 != INT_MAX){
                cur1 = last1;
            }else if(num>=nxt[lastnum] && last2!=INT_MAX){
                cur1 = last2;
            }else{
                cur1= INT_MAX;
            }
            if(nnum>=lastnum && last1!=INT_MAX){
                cur2 = last1+1;
            }else if(nnum>=nxt[lastnum] && last2!=INT_MAX){
                cur2 = last2+1;
            }else{
                cur2 = INT_MAX;
            }
            if(cur1== INT_MAX && cur2==INT_MAX){
                return -1;
            }
            last1 = cur1;
            last2 = cur2;

        }
        return min(last1, last2);
        
    
    }
};

int main(){

    Solution s;
    vector<int> ns = {9,27,81,27,3};
    cout << s.minOperations(ns);
}