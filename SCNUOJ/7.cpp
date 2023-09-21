#include "stdio.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){

    int a=1,b=1,n;

    scanf("%d", &n);

    if(n==1){
        printf("1");
        return 0;
    }
    n--;
    while(n--){
        int tmp = a + b;
        a = b;
        b = tmp;
    }

    printf("%d", b);

    return 0;
}