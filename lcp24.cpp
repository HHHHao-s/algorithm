#include "s.h"


class Solution {
private:
    priority_queue<long long> q1;
    priority_queue<long long,vector<long long>, greater<long long>> q2;
    long long left{0}, right{0};
    const long long MOD = 1e9+7;

    void addNum(long long num) {

        if(q1.empty() && q2.empty()){
            q1.push(num);
            left+=num;
        }else{
            if(q1.size()>q2.size()){     
                q1.push(num);        
                left+=num;    
                int tmp = q1.top(); 
                q2.push(tmp);
                right+=tmp;
                q1.pop();
                left-=tmp;
            }else{
                q2.push(num);
                right+=num;
                left+=q2.top();
                right-=q2.top();
                q1.push(q2.top());
                q2.pop();
            }       
        }
    }

    int get(){
        int a = 0;
        if(q1.size()>q2.size()){

            a = (right-(left-q1.top()))%MOD;
        }else{
            a = (right-left)%MOD;
        }
        if(a<0){
            a+=MOD;
        }
        return a;

    }



public:
    vector<int> numsGame(vector<int>& nums) {
        
        vector<int> ans{0};
        int n = nums.size();
        addNum(nums[0]);

        for(int i=1;i<n;i++){

            addNum(nums[i]-i);
            
            ans.push_back(get());


        }
        return ans;


    }
};

int main(){
    Solution s;
    vector<int> nums=  {1,2,3,4,5};
    printArr(s.numsGame(nums));
}