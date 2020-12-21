#include <iostream>

using namespace std;

template <class Type>
Type f1(Type x, Type y){
	return x/y;
}

int main(){
	cout << "5/2:" << f1 (5,2) << '\n';
	//cout << "5.0/2.0:" << f1 (5,2.0) << '\n'; using two different types is an error
	cout << "5.0/2.0:" << f1 (5.0,2.0) << '\n';
	return 0;
}

