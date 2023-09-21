#include "stdio.h"
using namespace std;
#include <vector>
#include <unordered_map>



int main(){

    
    int n;
    scanf("%d", &n);
    unordered_map<int,int> m;

    int a;
    int max_num=-1;
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        m[a]++;
        if(m[a]>n/2){
            max_num = a;
            break;
        }
    }

    printf("%d", max_num);

    return 0;
}