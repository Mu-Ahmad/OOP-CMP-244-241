#include <iostream>

using namespace std;

class A{
public:
	A()		{	cout << "Non-parameterized constructor of A\n";	}
};
class B:public A{
public:
	B(){	cout << "Non-parameterized constructor of B\n";	}
};

int main(){
	B b[5];
	return 0;
}
