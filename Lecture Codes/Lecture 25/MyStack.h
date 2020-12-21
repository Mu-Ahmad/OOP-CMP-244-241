#ifndef MYSTACK
#define MYSTACK

#include "Stack.h"

class MyIntegerStack:public Stack<int>{
public:
	MyIntegerStack(int size):Stack(size){}
};
#endif
