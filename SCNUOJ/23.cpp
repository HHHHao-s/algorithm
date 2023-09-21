#include <stdio.h>
#include <vector>
using namespace std;

int main(){

    int n,m;
    scanf("%d %d", &n, &m);

    vector<int> arr(m+1);
    

    for(unsigned long long i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        arr[a]++;
    }

    unsigned long long ans=0;
    unsigned long long low=1;
    for(unsigned long long i=1;i<=m;i++){
        if(arr[i]==0){
            continue;
        }
        unsigned long long high = low + arr[i]-1;
        ans= (ans+((((low+high)*arr[i])/2)*i))%1000000007;
        // for(unsigned long long j=low;j<=high;j++){
        //     ans = (ans+(j*i))%1000000007;
        // }
        low = high+1;
    }

    printf("%d", ans);

    return 0;
}