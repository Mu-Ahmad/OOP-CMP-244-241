#include <iostream>

using namespace std;

template <class Type1, class Type2>
Type1 f1(Type1 x, Type2 y){
	return x/y;
}

int main(){
	cout << "5/2 :" << f1 (5,2) << '\n';
	cout << "5/2.0 :" << f1 (5,2.0) << '\n';
	cout << "5.0/2 :" << f1 (5.0,2) << '\n';
	cout << "5.0/2.0 :" << f1 (5.0,2.0) << '\n';
	return 0;
}

