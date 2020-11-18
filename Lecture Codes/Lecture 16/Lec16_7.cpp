#include <iostream>

using namespace std;

/******************************************************************************************************
Reusability & reuability through aggregation
Reusability means to reuse the functions
In classes reusability means to call class functions, which requires object of the class

In aggregation, we want to reuse class A's functionality in class B

If we create class A's object with class B's object and remove class A's object with class B's object, it is called strong aggregation and there are two possible implementations of strong aggregation. One is without pointer and other is with pointer, with certain condition.

However, for weak aggregation, we can create object of class A at any stage and even without class B's object and we can use class A object in class B with pointer of class A. Similarly, we can remove object of class A without class B's object, if object A is not required.

******************************************************************************************************/
class A{
public:
	A(){	cout << "Object of A is created\n";}
	void fun_A() const{
		cout << "=====================================\n";
		cout << "=====================================\n";
		cout << "=====================================\n";
	}
	~A(){	cout << "Object of A is removed\n";}
};

class B{
	A *a;//May be weak aggregation
public:
	B(){	
		cout << "Object of B is created\n";
	}
	void createA(){
		a = new A;
	}
	void callFunctionA() const{
		a -> fun_A();
	}
	void removeA(){
		delete a;
	}
	~B(){	
		cout << "Object of B is removed\n";
	}

};
int main(){
	B objB;
	cout << "Object A is not created so far\n";
	objB.createA();
	objB.callFunctionA();
	objB.removeA();
	cout << "Object A is removed, whereas object B still exist\n";
	cout << "Now going to delete object B\n";
	return 0;
}
