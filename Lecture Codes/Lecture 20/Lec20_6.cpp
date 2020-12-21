#include <iostream>

using namespace std;

class A{
	int x;
protected:
	int y;
public:
	int z;
};
class B:protected A{
	void f(){
		y=10;
		z=20;
	}
};
class C:public B{
	void f(){
		y=2;	//ok
		z=3;	//ok
	}
};

int main(){
	C objc;
	objc.z=100;
	return 0;
}
