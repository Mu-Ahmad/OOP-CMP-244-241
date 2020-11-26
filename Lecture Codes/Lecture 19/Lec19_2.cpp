#include <iostream>

using namespace std;

class A{
public:
	void fa(){	cout << "A class function \n"; }
};
class B:public A{
public:
	void fa(){	cout << "B class function \n"; }
};
class C:public B{
public:
};

int main(){
	C c;
	B b;
	A a;
	a.fa();
	b.fa();
	c.fa();
	return 0;
}
