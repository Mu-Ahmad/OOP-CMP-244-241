#include <iostream>

using namespace std;

#define OUT_OF_BOUND_EXCEPTION -1
#define ILLEGAL_ARRAY_SIZE -2

template <class t>
class MyArray{
	t *x;
	int size;
public:
	MyArray(int size=10){
		if (size < 1)	throw ILLEGAL_ARRAY_SIZE;	
		this->size = size;
		x = new t[size];
	}
	int& operator[](const int index){
		if ( index >=0 && index < size )
			return x[index];
		throw OUT_OF_BOUND_EXCEPTION; 
	}
	~MyArray(){
		delete []x;
	} 
};
int main(){
	MyArray <int> x=3;
	x[0] = 34;
	x[1] = 45;
	x[2] = 55;
	cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
	return 0;
}
