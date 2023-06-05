#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class A {
public:
	A() {
		cout << "A的构造函数\n";
	}
	A(const A& a) {

		cout << "A的复制构造函数\n";
		
	}
	A(A&& a) {
		cout << "A的移动构造函数\n";
	}
	~A() {
		cout << "A的析构函数\n";
	}
};

class B
{
public:
	B() : pa_(std::make_shared<A>()) {
		cout << "B的默认构造函数\n";
	}
	B(const B& b) {
		cout << "B的复制构造函数\n";
		cout << "before" << endl;
		cout << "this->pa_.use_count()=" << pa_.use_count() << endl;
		cout << "this->pa_.get()=" << pa_.get() << endl;
		cout << "b.pa_.use_count()=" << b.pa_.use_count() << endl;
		cout << "b.pa_.get()=" << b.pa_.get() << endl;
		//pa_ = b.pa_; // 会分享同一份内存
		pa_ = std::make_shared<A>(*b.pa_);	
		cout << "this->pa_.use_count()=" << pa_.use_count() << endl;
		cout << "this->pa_.get()=" << pa_.get() << endl;
		cout << "b.pa_.use_count()=" << b.pa_.use_count() << endl;
		cout << "b.pa_.get()=" << b.pa_.get() << endl;
		
	}
	B(B&& b) noexcept{
		cout << "B的移动构造函数\n";
		cout << "before" << endl;
		cout << "this->pa_.use_count()=" << pa_.use_count() << endl;
		cout << "this->pa_.get()=" << pa_.get() << endl;
		cout << "b.pa_.use_count()=" << b.pa_.use_count() << endl;
		cout << "b.pa_.get()=" << b.pa_.get() << endl;
		cout << "after" << endl;
		pa_ = std::move(b.pa_);
		cout << "this->pa_.use_count()=" << pa_.use_count() << endl;
		cout << "this->pa_.get()=" << pa_.get() << endl;
		cout << "b.pa_.use_count()=" << b.pa_.use_count() << endl;
		cout << "b.pa_.get()=" << b.pa_.get() << endl;
		
	}
	B& operator=(B&& b) noexcept { // 若值传递，会调用拷贝构造函数
		cout << "B的移动赋值函数\n";
		cout << "before" << endl;
		cout << "this->pa_.use_count()=" << pa_.use_count() << endl;
		cout << "this->pa_.get()=" << pa_.get() << endl;
		cout << "b.pa_.use_count()=" << b.pa_.use_count() << endl;
		cout << "b.pa_.get()=" << b.pa_.get() << endl;
		pa_ = std::move(b.pa_);
		cout << "this->pa_.use_count()=" << pa_.use_count() << endl;
		cout << "this->pa_.get()=" << pa_.get() << endl;
		cout << "b.pa_.use_count()=" << b.pa_.use_count() << endl;
		cout << "b.pa_.get()=" << b.pa_.get() << endl;
		
		return *this;
	}
	~B() {
		cout << "B的析构函数\n";
		cout << "this->pa_.use_count()=" << pa_.use_count() << endl;
		cout << "this->pa_.get()=" << pa_.get() << endl;
		
	}
	void getPa_() {

		cout << "this->pa_.get()" << this->pa_.get() << endl;
	}
private:
	std::shared_ptr<A> pa_;
};


B& getB() {
	B ret{};
	return ret;

}


int main() {

	B b1 = getB();
	B b2{};
	(b2 = std::move(b1)).getPa_();
	
	system("pause");
	return 0;
}