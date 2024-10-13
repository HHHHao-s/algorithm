#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <future>
#include <thread> // 包含sleep_for
#include <chrono> // 包含chrono_literals
#include <stack>
#include <stdio.h>
using namespace std;

int main(){

    int n= 50;
    printf("%d\n", n);

    for(int i=0;i<n;i++){

        printf("%d\n", rand()%(1<<15));    

    }

}