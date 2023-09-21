#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution{
public:

    int find(string s1, string s2){
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1));

        for(int i=1;i<=m;i++){
            char c1 = s1[i-1];
            for(int j=1;j<=n;j++){
                char c2 = s2[j-1];
                if(c1==c2){
                    dp[i][j] = max({dp[i-1][j-1]+1,dp[i-1][j],dp[i][j-1]});
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[m][n];


    }

};


int main(){

    string s1,s2;
    cin >> s1 >> s2;

    Solution s;

    cout << s.find(s1,s2);


    return 0;
}