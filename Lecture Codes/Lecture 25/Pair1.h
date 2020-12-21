#ifndef PAIR1
#define PAIR1

#include <iostream>

using namespace std;

template <class T>
class Pair{
	T a,b;
public:
	Pair(){}
	Pair(T&, T&);
	void set(T&, T&);
	friend ostream& operator << (ostream &out, const Pair &p){
		out << '(' << p.a << ',' << p.b << ") ";
		return out;
	}
};
template <class Type>
Pair<Type>::Pair(Type &a, Type &b){
	set(a,b);
}
template <class Type>
void Pair<Type>::set(Type &a, Type &b){
	this->a = a;
	this->b = b;
}
#endif
