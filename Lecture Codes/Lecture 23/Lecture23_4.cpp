#include <iostream>

using namespace std;

//Making copy constructor private is to restrict use of copy constructor, which simply
//means we don't want that user can use copy constructor
class Test{
	//Here copy constructor is private and can't be used outside the class
	Test(Test &t){}
	//Here constructor is also private and can't be used outside the class
	Test(){}
public:
	void f1(){	cout << "This is a member function\n";	}
};
int main(){
	Test t1;
	return 0;
}
