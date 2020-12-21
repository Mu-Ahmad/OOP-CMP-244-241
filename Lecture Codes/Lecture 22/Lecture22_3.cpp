#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Multiple Inheritance
//A class has multiple direct parents (instead of hierarchy)
class Parent1{
public:
	Parent1(){	cout << "Constructor of Parent 1\n";	}
	~Parent1(){	cout << "Destructor of Parent 1\n";	}
};
class Parent2{
public:
	Parent2(){	cout << "Constructor of Parent 2\n";	}
	~Parent2(){	cout << "Destructor of Parent 2\n";	}
};
class Child:public Parent1, public Parent2{
public:
	Child(){	cout << "Constructor of Child\n";	}
	~Child(){	cout << "Destructor of Child\n";		}
};
int main(){
	Child child;
	return 0;
}

