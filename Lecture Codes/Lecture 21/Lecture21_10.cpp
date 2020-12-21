#include <iostream>

using namespace std;

//Abstract class may have data members, constructors and destructors (for dynamic memory)
class P{
protected:
	int x;
public:
	P(int x){	this->x = x;	}
	virtual void f1()=0;
};
class C1:public P{
public:
	C1(int x):P(x){		}
	void f1(){	cout << "F1 of C1, Value:" << x << '\n';	}
};
class C2:public P{
public:
	C2(int x):P(x){		}
	void f1(){	cout << "F1 of C2, Value:" << x << '\n';	}
};
class C3:public P{
public:
	C3(int x):P(x){		}
	void f1(){	cout << "F1 of C3, Value:" << x << '\n';	}
};
class C11:public C1{
public:
	C11(int x):C1(x){		}
	void f1(){	cout << "F1 of C11, Value:" << x << '\n';	}
};
int main(){
	P *p;
	int choice, value;
	for (int i=0;i<10;i++){
		choice = rand() % 4+1;
		value = rand() % 1000;
		switch(choice){
			case 1:	cout << "Object C1 Created\n";	p = new C1(value);	break;
			case 2:	cout << "Object C2 Created\n";	p = new C2(value);	break;
			case 3:	cout << "Object C3 Created\n";	p = new C3(value);	break;
			case 4:	cout << "Object C11 Created\n";	p = new C11(value);break;
		}
		p -> f1 ();
		delete p;
	}
	return 0;
}
