#include <iostream>

using namespace std;

class P{
public:
	//Virtual function allows child class to override functions
	virtual void f1(){	cout << "F1 of P\n";	}
};
class C1:public P{
public:
	//Function Overriding
	void f1(){	cout << "F1 of C1\n";	}
};
class C2:public P{
public:
	void f1(){	cout << "F1 of C2\n";	}
};
class C3:public P{
public:
	void f1(){	cout << "F1 of C3\n";	}
};
class C11:public C1{
public:
	void f1(){	cout << "F1 of C11\n";	}
};
int main(){
	P *p[5];
	p[0] = new P;
	p[1] = new C1;
	p[2] = new C2;
	p[3] = new C3;
	p[4] = new C11;
	for (int i=0;i<5;i++){
		p[i]->f1();//Function is called from object class, if overridden by object class
		delete p[i];
	}
	return 0;
}
