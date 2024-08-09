#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n ,m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t;
            cin >>t;
            grid[i][j] = t;
        }
    }
    vector<int > dp(1<<m, 0);
    for(int l=0;l<n;l++){
        vector<int> got(1<<m);
        for(int i=0;i<m;i++){
            got[(1<<i)] = grid[l][i];
        }
        for(int i = 1;i<(1<<m);i++){
            
            got[i] = got[(i^(i&(-i)))] + got[i&(-i)];
        }
        vector<int> tmp_dp(1<<m ,0);

        for(int i=1;i<(1<<m);i++){
            int reverse = ((i<<1) | (i>>1)) &((1<<m)-1);
            for(int j=0;j<(1<<m);j++){
                if((j&reverse)==0)
                    tmp_dp[i] = max(tmp_dp[i], got[i] + dp[j]);
            }

        }
        dp = tmp_dp;

    }
    int ret= 0;
    for(int i=0;i<(1<<m);i++){
        ret = max(dp[i], ret);
    }
    cout << ret;

}
// 64 位输出请用 printf("%lld")