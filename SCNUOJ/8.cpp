#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n=4, cap=10;

    scanf("%d %d", &n, &cap);

    int w[4]={7,3,4,5};
    int v[4]={42,12,40,25};

    vector<vector<int>> dp(cap+1, vector<int>(n+1));
    dp[0][0] = 0;

    for(int i=1;i<=cap;i++){
        for(int j=1;j<=n;j++){
            int weight = w[j-1];
            int value = v[j-1];
            if(weight<=i){
                dp[i][j] = max(dp[i-weight][j-1]+value, dp[i-1][j]);
            }
        }
    }

    printf("%d", dp[cap][n]);

    return 0;
}