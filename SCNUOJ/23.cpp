#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main(){

    int n,m;
    scanf("%d %d", &n, &m);

    vector<int> arr(m+1);
    

    for(int i=0;i<n;i++){
        int t;
        scanf("%d", &t);
        arr[t]++;

    }
    
    long long ans=0;
    int begin=1;
    for(int i=1;i<=m;i++){
        if(arr[i]==0){
            continue;
        }

        int end = arr[i]+begin-1;
        ans=(ans+((long long)i*((long long)(end + begin)*(long long)(arr[i])/(long long)2)))% 1000000007;
        begin+=arr[i];
    }
    cout << ans;

    return 0;

}