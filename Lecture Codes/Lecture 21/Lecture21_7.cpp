#include <iostream>

using namespace std;

//Function is virtual, still polymorphic behavior is missing, because some child classes
//has not overrided virtual function, the solution is to create pure virtual function
class P{
public:
	virtual void f1(){	cout << "F1 of P\n";	}
};
class C1:public P{
public:
	//void f1(){	cout << "F1 of C1\n";	}
};
class C2:public P{
public:
	void f1(){	cout << "F1 of C2\n";	}
};
class C3:public P{
public:
//	void f1(){	cout << "F1 of C3\n";	}
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
			case 0:	cout << "Object P Created\n";	p = new P; break;
			case 1:	cout << "Object C1 Created\n";	p = new C1;	break;
			case 2:	cout << "Object C2 Created\n";	p = new C2;	break;
			case 3:	cout << "Object C3 Created\n";	p = new C3;	break;
			case 4:	cout << "Object C11 Created\n";	p = new C11;break;
		}
		p -> f1 ();//If function not overrided then function called from pointer or parent class
		delete p;
	}
	return 0;
}
