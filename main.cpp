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

using namespace std;
class A{

public:
    A(){
        cout << "default" << endl;
    }

    A(int x) : data(x){
        cout << "x=" << x << endl;
    }

    A(const A& other){
        cout << "copy" << endl;
        data=  other.data;

    }

    A(A&& other){
        cout << "move" << endl;
        data = other.data;
    }


    ~A(){

    }

   
private:
    int data;

};

A f(A a){

    cout<< "f" << endl;


    return a;

}

A f(){
    A a(2);
    cout<< "f" << endl;


    return a;

}

int main() {

    A tmp = f({1});

    A tmp2 = f();

}