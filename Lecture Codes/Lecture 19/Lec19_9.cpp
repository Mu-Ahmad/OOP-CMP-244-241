#include <iostream>

using namespace std;

class A{
	char c;
public:
	A(char  c){	this->c = c;	}
	friend ostream& operator << (ostream &, const A&);
};
ostream& operator << (ostream &out, const A &a){
	out << a.c << ' ';
	return out;
}
class B:public A{
	int y;
public:
	B(char x, int y):A(x){	this->y = y;	}
	friend ostream& operator << (ostream &, const B&);
};
ostream& operator << (ostream &out, const B &b){
	//To call ostream of parent type cast child class object	
	out << (A)b << b.y << '\n';
	return out;
}
int main(){
	B b('T',6);
	cout << b;
	return 0;
}
