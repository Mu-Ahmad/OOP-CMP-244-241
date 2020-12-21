#include <iostream>

using namespace std;

//Making copy constructor private is to restrict use of copy constructor, which simply
//means we don't want that user can use copy constructor
class Test{
	Test(Test &t){}
public:
	Test(){}
};
int main(){
	Test t1, t2;
	return 0;
}
