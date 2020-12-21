#ifndef PAIR
#define PAIR

#include <iostream>

using namespace std;

template <class T>
class Pair{
	T a,b;
public:
	Pair(){}
	Pair(T &a, T &b){	set(a,b);}
	void set(T &a, T &b){
		this->a = a;
		this->b = b;
	}
	friend ostream& operator << (ostream &out, const Pair &p){
		out << '(' << p.a << ',' << p.b << ") ";
		return out;
	}
};
#endif
