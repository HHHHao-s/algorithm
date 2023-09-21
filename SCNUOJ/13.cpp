#include <queue>
#include <iostream>
using namespace std;


int main(){

    priority_queue<int> pq;

    int d;
    while(cin>>d){
        pq.push(d);
    }

    

    int a=pq.top();
    pq.pop();
    int b=pq.top();
    pq.pop();
    int c=pq.top();
    pq.pop();

    while(b+c<a && !pq.empty()){
        int tmp = pq.top();
        pq.pop();
        a=b;
        b=c;
        c=tmp;

    }

    if(b+c>a){
        cout<< a+b+c;
    }else{
        cout<< 0;
    }
    


    return 0;
}