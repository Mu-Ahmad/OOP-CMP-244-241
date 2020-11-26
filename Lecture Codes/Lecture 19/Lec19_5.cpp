#include <iostream>

using namespace std;

class A{
public:
	A()		{	cout << "Non-parameterized constructor of A\n";	}
	A(int x){	cout << "int paramerized constructor of A\n";	}
};
class B:public A{
public:
	B():A(5){	cout << "Non-parameterized constructor of B\n";	}
	B(int x){	cout << "int paramerized constructor of B\n";	}
};

int main(){
	B b1;
	cout << "-----------------\n";
	B b2(5); 
	return 0;
}
