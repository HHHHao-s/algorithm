#include <bits/stdc++.h>

using namespace std;

int main(){

    int n=4, cap=10;

    scanf("%d %d", &n, &cap);
    vector<long long> W, V;
    for(int i=0;i<n;i++){
        long long t;
        cin >> t;
        W.push_back(t);
    }
    for(int i=0;i<n;i++){
        long long t;
        cin >> t;
        V.push_back(t);
    }

    vector<vector<long long>> dp(n+1, vector<long long>(cap+1));
    // for(int i=W[0];i<=cap;i++){
    //     dp[1][i] = V[0];
    // }

    for(long long i=1;i<=n;i++){
        for(long long j=cap;j>=1;j--){

            if(j-W[i-1]>=0){
                dp[i][j] = max({ dp[i-1][j-W[i-1]]+V[i-1], dp[i-1][j]});
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][cap];

    return 0;
}