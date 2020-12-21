#include <iostream>

using namespace std;

class A{
public:
	void f1(){	cout << "f1 of A\n";	}
};
class B{
public:
	void f1(){	cout << "f1 of B\n";	}
};
class C{
public:
	void f1(){	cout << "f1 of C\n";	}
};
class P{
public:
	virtual void f1()=0;
};
class A1:public P{
public:
	void f1(){	cout << "f1 of A1\n";	}
};
class B1:public P{
public:
	void f1(){	cout << "f1 of B1\n";	}
};
class C1:public P{
public:
	void f1(){	cout << "f1 of C1\n";	}
};

int main(){
	A *a;	B *b;	C *c;
	P *p;
	int choice;
	cout << "Enter your choice 1-3:";
	cin >> choice;
	switch (choice){
		case 1:	a = new A;	break;
		case 2:	a = new A;	break;
		case 3:	a = new A;	break;
	}
	switch (choice){
		case 1:	p = new A1;	break;
		case 2:	p = new B1;	break;
		case 3:	p = new C1;	break;
	}
	if 		(choice==1)	a->f1();
	else if (choice==2)	b->f1();
	else if (choice==3)	c->f1();
	p->f1();
	return 0;
}
