#include <iostream>

using namespace std;

//Abstract class with 2 pure virtual functions
class A{
public:
	virtual void f1()=0;
	virtual void f2()=0;
};
//Abstract class with 1 pure virtual function
class B:public A{
public:
	void f1(){		}
	void f2(){		}
	virtual void f3()=0;
};
//Concrete class, a class with all functions implemented
class C:public B{
public:
	void f3(){		}
};
int main(){
	C objC;
	return 0;
}
