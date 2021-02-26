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
	try{
		MyArray <int> x=-3; 
		x[0] = 34;
		x[1] = 45;
		cout << x[0] << ' ' << x[1] << '\n';
	}catch(int type){
		if (type==OUT_OF_BOUND_EXCEPTION)
			cout << "Array Index Out of Bound\n";
		else if (type == ILLEGAL_ARRAY_SIZE)
			cout << "Array size is negative\n";
	}catch (bad_alloc ba){
		cout << "Out of memory\n";
	}
	
	return 0;
}
