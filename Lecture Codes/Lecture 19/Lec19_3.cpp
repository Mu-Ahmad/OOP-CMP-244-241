#include <iostream>

using namespace std;

class A{
public:
	void fa(){	cout << "A class function \n"; }
};
class B:public A{
public:
};
class C:public B{
public:
	void fa(){	cout << "C class function \n"; }
};
class D:public C{
public:
};
class E:public D{
public:
};

int main(){
	B b;
	b.fa();
	C c;
	c.fa();
	D d;
	d.fa();
	E e;
	e.fa();
	return 0;
}
