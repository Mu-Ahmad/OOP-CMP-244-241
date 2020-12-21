#include <iostream>

using namespace std;

//Making copy constructor private is to restrict use of copy constructor, which simply
//means we don't want that user can use copy constructor
class Test{
	//Here copy constructor is private and can't be used outside the class
	Test(Test &t){}
	Test(){}
public:
};
int main(){
	//Test t1, t2;
	cout << "There is no error so far\n";
	return 0;
}
