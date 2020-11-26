#include <iostream>

using namespace std;

class A{
public:
	void fa(){	cout << "A class function \n"; }
};
class B:public A{
public:
	//Redefinition of function
	void fa(){	cout << "B class function \n"; }
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
	D d;
	d.B::fa();
	E e;
	e.fa();
	return 0;
}
