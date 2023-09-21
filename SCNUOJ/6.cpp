#include "stdio.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long calc(long long m, long long n){

    long long up_mul=1;
    if(m==0 || n==0){
        return 1;
    }
    if(m>n){
        swap(m,n);
    }
    
    for(long long i=m,j=n;i>0;i--,j--){
        up_mul*=j;
    }
    long long down_mul=1;
    for(long long i=1;i<=m;i++){
        down_mul*=i;
        
    }

    return up_mul/down_mul;

}

int main(){

    int m,n;
    scanf("%d %d", &m, &n);

    printf("%ld", calc(m-1,m+n-2));

    return 0;
}