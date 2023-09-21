#include "stdio.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){

    int n,k;
    scanf("%d %d", &n, &k);

    // small heap
    priority_queue<int, vector<int> , greater<int>> h;


    for(int i=0;i<k;i++){
        int a;
        scanf("%d", &a);
        h.push(a);
    }

    for(int i=k;i<n;i++){
        int a;
        scanf("%d", &a);
        if(a>h.top()){
            h.pop();
            h.push(a);
        }
    }
    printf("%d", h.top());

    return 0;
}