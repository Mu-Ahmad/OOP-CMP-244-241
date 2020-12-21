#ifndef MYSTACK1
#define MYSTACK1

#include <iostream>

using namespace std;

#include "Stack.h"

template <class T>
class MyStack1:public Stack<T>{
public:
	MyStack1(int size):Stack<T>(size){}
	T seeTop(){	if (Stack<T>::p>0)    return Stack<T>::data[Stack<T>::p-1];	}
};
#endif
