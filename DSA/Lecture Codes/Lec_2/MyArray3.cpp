#include <iostream>

using namespace std;

#define OUT_OF_BOUND_EXCEPTION -1
#define ILLEGAL_ARRAY_SIZE -2
#define OUT_OF_MEMORY -3

template <class t>
class MyArray{
	t *x;
	int size;
public:
	MyArray(int size=10){
		if (size < 1)	throw ILLEGAL_ARRAY_SIZE;	
		this->size = size;
		x = new t[size];
		if (x == NULL) throw OUT_OF_MEMORY;
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
		MyArray<int> x1=(1000000000);
		MyArray<int> x2=(1000000000);
		//
		//
	}catch(int type){
		if (type==OUT_OF_BOUND_EXCEPTION)
			cout << "Array Index Out of Bound\n";
		else if (type == ILLEGAL_ARRAY_SIZE)
			cout << "Array size is negative\n";
	}catch (bad_alloc ba){
		cout << "Memory not available\n";
	}
	return 0;
}
