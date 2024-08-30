#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


double f(double x){
    return x*x-1;
}

double ff(double x){
    return 2*x;
}

int main() {
    
    double x1 = 10;
    double x2 = 10;
    do{
        x1 =x2;
        x2=x1 - f(x1)/ff(x1);
        

    }while(abs(x1-x2)>1e-5);

    cout << x1;


}