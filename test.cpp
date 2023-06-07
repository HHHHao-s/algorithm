#include "s.h"

class Base{
public:
	Base() = default;

	Base(Base & other){
		cout << "Base 的拷贝构造函数" << endl;
	}

	virtual void print(){
		cout << "Base::print" << endl;
	}

private:

};

class Derived : public Base{
public:

	Derived() = default;

	Derived(Derived & other){
		cout << "Derived 的拷贝构造函数" << endl;
	}

	Derived(int a__): a(a__){
		cout << "Derived 的int a构造函数" << endl;
	}

	virtual void print(){
		cout << "Derived::print" << endl;
	}


	int a{0};
};


int main(){

	Base *b1 = new Derived(123);
	Base *b2 = new Base(*b1);
	Derived *d = dynamic_cast<Derived*>(b2);
	cout << d->a;
	return 0;
}