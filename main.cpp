#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node{
int val;
struct  Node *next;
};

Node *gen(vector<int> nums){

    Node *ret = new Node;
    Node *next = ret;

    for(int num:nums){

        Node *newn = new Node;
        newn->val = num;
        next ->next = newn;
        next=next->next;

    }
    return ret->next;

}


int main() {
    
    vector<int> a1 = {1,3,5,7};
    vector<int> a2 = {2,4,6,8};




    vector<Node*> ls{gen(a1), gen(a2)};

    map<int, deque<Node*>> m;

    

    Node * ret=new Node;
    Node * last=nullptr;

    ret = last;
    int i=0;
    for(auto p: ls){

        m[p->val].push_back(p);

    }

    while(!m.empty()){

        auto p = m.begin()->second.front();
        m.begin()->second.pop_front();
        if(m.begin()->second.empty()){
            
            m.erase(m.begin()->first);
        }
        if(p->next!=nullptr){
            m[p->next->val].push_back(p->next);
        }
        p->next = nullptr;
        last->next = p;
        last = last->next;
        
        
        

    }

    for(auto p =ret->next; p!=nullptr;p=p->next){
        cout << p->val << ' ';
    }


}
/*
const int* ptr
int* const ptr

unique
shared
weak

shared_prt<int> a = b;

*/