#include <iostream>

using namespace std;

class A{
	int x;
protected:
	int y;
public:
	int z;
};
class B:public A{
};
class C:public B{
};

int main(){
	C c;
	//c.x=10;	//error because x is private
	//c.y=20;	//error because y is protected
	c.z=30;		//No error
	return 0;
}
