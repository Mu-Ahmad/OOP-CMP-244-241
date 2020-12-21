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

int main(){
	A *a;	B *b;	C *c;
	int choice;
	cout << "Enter your choice 1-3:";
	cin >> choice;
	switch (choice){
		case 1:	a = new A;	break;
		case 2:	a = new A;	break;
		case 3:	a = new A;	break;
	}
	if 		(choice==1)	a->f1();
	else if (choice==2)	b->f1();
	else if (choice==3)	c->f1();
	return 0;
}
