#include "s.h"
#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std::chrono;

int main(){

    auto start1 = high_resolution_clock::now();

    priority_queue<int> q;

    int a;
    
    
    cout << scanf("%c", &a) << endl;
    cout << a <<endl;

    // while(scanf("%d",&a)!=EOF){
    //     cout << a;
    //     q.push(a);

    // }

    vector<int> arr;

    while(!q.empty()){
        arr.push_back(q.top());
        q.pop();
    }

    auto end1 = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end1 - start1);

    cout << arr.size() << endl;

    // 输出时间差
    cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << endl;

    return 0;
}