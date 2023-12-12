#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        

        vector<int> new_num =move(nums);
        nums.push_back(1);
        for(int x:new_num){
            nums.push_back(x);
        }
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i=n-3;i>=0;i--){
            for(int j=i+2;j<n;j++){
                for(int k=i+1;k<j;k++){
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][n-1];
        
    }
};

int main(){

    string line;
    getline(cin, line);
    istringstream iss(line);
    int num;
    vector<int> bullons;
    while(iss>>num){
        bullons.push_back(num);        
    }

    Solution s;
    cout << s.maxCoins(bullons);

    return 0;
}