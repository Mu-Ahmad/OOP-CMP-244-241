#include <iostream>

using namespace std;

//Polymorphism - different behaviors of same name function
//We have discussed function overloading, constructor overloading, operator overloading
//the concept referes to static polymorphism, binding operation done by compiler
//Polymorphism (without word static) refers to dynamic polymorphism
class P{
public:
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
	P *p;
	int choice;
	for (int i=0;i<10;i++){
		choice = rand() % 5;
		switch(choice){
			case 0:	p = new P; break;
			case 1:	p = new C1;	break;
			case 2:	p = new C2;	break;
			case 3:	p = new C3;	break;
			case 4:	p = new C11;	break;
		}
		p -> f1 ();
		delete p;
	}
	return 0;
}
