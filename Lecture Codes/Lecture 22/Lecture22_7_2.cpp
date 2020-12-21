#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Parent1{
public:
	void abc(){	cout << "abc of Parent 1\n";	}
	void def(){	cout << "def of Parent 1\n";	}
};
class Parent2{
public:
	void abc(){	cout << "abc of Parent 2\n";	}
	void ghi(){	cout << "ghi of Parent 2\n";	}
};
class Child:public Parent1, public Parent2{
public:
	void abc(){	Parent1::abc();	}
};
int main(){
	Child child;
	child.abc();
	return 0;
}
