#include "s.h"

class Test{
public:

	void insert(){
		for(int i=0;i<1024;i++){
			array_[i] = {i,1024-i};
		}

	}

	std::pair<int,int> array_[1024];
};



int main(){

	Test t;
	t.insert();
	auto out = upper_bound(&t.array_[0],&t.array_[1024], 300, []( const int &lhs,const std::pair<int,int> &rhs) -> bool{
		return lhs<rhs.first;
		
	});

	cout<<out->first << " "<< out->second;
	return 0;
}