#include <iostream>
#include <vector>
#include <map>
#include <deque>

using namespace std;

/*




*/

struct X{

    X(int data){
        pa = new int;
        *pa = data;
    }

    X(const X& rhs) {
        pa = rhs.pa;
    }

    X(X&& rhs) noexcept{
        
        pa = new int;
        *pa = *rhs.pa;
        cout << pa << ' ' << endl;
    }

    ~X(){
        delete pa;
    }


int *pa;

};





int main()
{
    vector<X> arr;

    for(int i=0;i<3;i++){
        
        arr.emplace_back(i);
    }


}
