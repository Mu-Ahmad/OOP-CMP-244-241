#include <iostream>

using namespace std;


class P{
public:
	//Pure virtual function, enforces child classes to override function
	//Either child classes has to override pure virtual function, or there will be problem
	virtual void f1()=0;
};
class C1:public P{
public:
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
	P *p;
	int choice;
	for (int i=0;i<10;i++){
		choice = rand() % 4+1;
		switch(choice){
			case 1:	cout << "Object C1 Created\n";	p = new C1;	break;
			case 2:	cout << "Object C2 Created\n";	p = new C2;	break;
			case 3:	cout << "Object C3 Created\n";	p = new C3;	break;
			case 4:	cout << "Object C11 Created\n";	p = new C11;break;
		}
		p -> f1 ();
		delete p;
	}
	return 0;
}
