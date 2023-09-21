#include "stdio.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){

    int n,k;
    scanf("%d %d", &n, &k);

    // big heap
    priority_queue<int> h;


    for(int i=0;i<k;i++){
        int a;
        scanf("%d", &a);
        h.push(a);
    }

    for(int i=k;i<n;i++){
        int a;
        scanf("%d", &a);
        if(a<h.top()){
            h.pop();
            h.push(a);
        }
    }

    vector<int> arr(k);
    for(int i=0;i<k;i++){
        arr[i] = h.top();
        h.pop();
    }

    for(int i=k;i-->0;){
        printf("%d ",arr[i]);
    }


    return 0;
}
