#include <iostream>

using namespace std;

class Point{
	int x,y;
public:
	Point(int x=0, int y=0){	this->x = x;	this->y = y;	}
	friend ostream& operator << (ostream &out, const Point &p){
		out << p.x << ',' << p.y << "  ";
		return out;
	}
};
class A{
	int *x;
	const int SIZE;
	A& copy(const A &a){
		x = new int[SIZE];	
		for (int i=0;i<SIZE;i++)
			x[i] = a.x[i];
		return *this;
	}
public:
	A(int s=10):SIZE(s){	x = new int[SIZE];	initRandomly();	}
	void initRandomly(){
		for (int i=0;i<SIZE;i++)
			x[i]=rand()%100;
	}
	A(const A &a):SIZE(a.SIZE){	copy(a);	}
	A& operator = (const A &a){
		delete []x;
		return copy(a);
	}
	~A(){	delete []x;	}
	friend ostream& operator << (ostream &out, const A &a);
};
ostream& operator << (ostream &out, const A &a){
	for (int i=0;i<a.SIZE;i++)
		out << a.x[i] << ' ';
	out << '\n';
	return out;
}

template <class Type>
void swap1(Type &x, Type &y){
	Type temp = x;
	x = y;
	y = temp;
}

int main(){
	A obj1, obj2;
	cout << "Obj1:" << obj1 << "Obj2:" << obj2 << '\n';
	swap (obj1, obj2);
	cout << "Obj1:" << obj1 << "Obj2:" << obj2 << '\n';

	Point p1(3, 7), p2(4, 8);
	cout << "P1:" << p1 << "P2:" << p2 << '\n';
	swap (p1, p2);
	cout << "P1:" << p1 << "P2:" << p2 << '\n';
	return 0;
}

