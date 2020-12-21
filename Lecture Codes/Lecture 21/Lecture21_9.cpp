#include <iostream>

using namespace std;

//Class with one or more pure virtual function becomes abstract
//Abstract class is not instantiable, means we can't create object of abstract class
//However, pointer and reference of abstract class exist, similarly abstract class may have
//non-virtual functions for child classes
class P{
public:
	virtual void f1()=0;
	void f2(){	cout << "Non-virtual function of parent\n";	}
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
		p -> f2 ();
		delete p;
	}
	return 0;
}
