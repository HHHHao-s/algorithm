#include "stdio.h"
#include <vector>

using namespace std;


int main(){

    int n;
    scanf("%d", &n);

    vector<int> pre(n);
    
    int sum=0;
    int max_sum=0;
    int min_num=-10000000;
    int cnt=0;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        if(a>0){
            cnt++;           
        }else{
            min_num=max(min_num, a);
        }
        
        if(a+sum<0){
            max_sum = max(max_sum, sum);
            sum=0;
        }else{
            if(a<0){
                max_sum=max(sum, max_sum);
            }
            sum+=a;
            

        }
    }

    max_sum = max(max_sum,sum);

    if(cnt==0){
        printf("%d", min_num);
    }else{
        printf("%d", max_sum);
    }

    

    return 0;
}