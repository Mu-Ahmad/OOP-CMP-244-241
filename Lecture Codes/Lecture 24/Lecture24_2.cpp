#include <iostream>

using namespace std;

//Templates
//Template is a power ful feature provided in C++ to write somehow generic code and
//use that code for different data types, provided that logic is same, however, operations
//will be performed according to data type, like integer division, complete division
//IO operations

//Compiler compiles multiple codes against template code according to different data types
// used with that code

template <class GenericType>
void swap1(GenericType &x, GenericType &y){
	GenericType temp = x;
	x = y;
	y = temp;
}
int main(){
	int a=5, b=10;
	float f1=3.4, f2=7.5;
	char c1='T', c2='R';
	cout << "A:" << a << " B:" << b << '\n';
	swap1(a,b);
	cout << "A:" << a << " B:" << b << '\n';
	cout << "F1:" << f1 << " F2:" << f2 << '\n';
	swap1(f1,f2);
	cout << "F1:" << f1 << " F2:" << f2 << '\n';
	cout << "C1:" << c1 << " C2:" << c2 << '\n';
	swap1(c1,c2);
	cout << "C1:" << c1 << " C2:" << c2 << '\n';
	swap1(a,b);
	return 0;
}

