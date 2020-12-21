#include <iostream>

using namespace std;

class A{
	int x;
protected:
	int y;
public:
	int z;
};
class B:private A{
};
class C:public B{
	void f(){
		//x=1;	//error because x is private
		//y=2;	//error because of private inheritance now y is also private
		//z=3;	//error because of private inheritance now z is also private
	}
};

int main(){
	C objc;
	return 0;
}
