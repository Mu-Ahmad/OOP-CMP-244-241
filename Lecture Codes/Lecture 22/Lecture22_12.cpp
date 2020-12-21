#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class GP{
public:
	GP(){	cout << "GP\n";	}	
	void f1(){	cout << "F1 of GP\n";	}
};
class Parent1:public GP{
public:
	Parent1(){	cout << "Parent1\n";	}
};
class Parent2:public GP{
public:
	Parent2(){	cout << "Parent2\n";	}
};
class Child:public Parent1, public Parent2{
public:
	Child(){	cout << "Child\n";	}
};
int main(){
	Child child;
	child.Parent1::f1();
	return 0;
}
