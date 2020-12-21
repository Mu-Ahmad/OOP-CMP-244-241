#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Diamond Problem
//There exist two classes with common parent, you may say sibling classes
//Some class inherit both sibling classes
class GP{
public:
	GP(){	cout << "GP\n";	}	
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
	return 0;
}
