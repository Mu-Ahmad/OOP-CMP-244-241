#ifndef STACK
#define STACK

template <class Type>
class Stack{
protected:
	Type *data;
	int p;//stack pointer, use to point last element
	const int SIZE;
public:
	Stack(int size):SIZE(size){
		p = 0;
		data = new Type[size];
	}
	void push(Type &element){
		if (p<SIZE)
			data[p++] = element;
	}
	Type pop(){
		if (p>0)
			return data[--p];
	}
	~Stack(){	delete []data;	}
};
#endif
