#include <iostream>

using namespace std;

//Parent - Child 		Super - Sub		Generalize - Special 		Base - Derived 

//Access specifier 	
//public		-	Accessible to everyone, everywhere
//private		-   Accessible within class or friends
//protected		- 	Accessible in child classes 
//In absence of inheritance protected and private are same
//In child classes parent class public and protected members have similar access

class Point2D{
protected:
	int x, y;
public:
	Point2D(int x=0, int y=0){	this->x=x;	this->y=y;	} 
};
class Point3D:public Point2D{	//Inheritance
	int z;
public:
	Point3D(int x=0, int y=0, int z=0):Point2D(x, y){	this->z = z;	} 
	//In inheritance protected members are accessible
	void show() { cout << "X:" << x << ", Y:" << y << ", Z:" << z << '\n';		}
};
class Line{//	Aggregation
	Point3D p1, p2;
public:
	Line(int x1, int y1, int x2, int y2):p1(x1, y1), p2(x2, y2){}
	void show(){	cout << "Line has two points:\n";		p1.show();	p2.show();			}
	//In aggregation protected members are like private
	//int getPoint1X(){	return p1.x;	}
};

int main(){
	Line line(3,5,6,1);
	line.show();
	//Point3D p(3,5,1);
	//p.show();
	return 0;
}
