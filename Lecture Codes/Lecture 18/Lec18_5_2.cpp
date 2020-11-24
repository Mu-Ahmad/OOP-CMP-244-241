#include <iostream>

using namespace std;

//Parent - Child 		Super - Sub		Generalize - Special 		Base - Derived 

//Access specifier 	
//public		-	Accessible to everyone, everywhere
//private		-   Accessible within class or friends
//protected		- 	Accessible in child classes 
//In absence of inheritance protected and private are same
//For child classes public and protected are same

class Point2D{
protected:
	int x, y;
public:
	Point2D(int x=0, int y=0){	this->x=x;	this->y=y;	} 
};
class Point3D:public Point2D{
	int z;
	int x;
public:
	Point3D(int x=0, int y=0, int z=0):Point2D(x, y){	this->x= 0;  this->z = z;	} 
	void show() { cout << "Parent-X:" << Point2D::x << ", X:" << x << ", Y:" << y << ", Z:" << z 
					<< '\n';		
	}
};

int main(){
	Point3D p(3,5,1);
	p.show();
	return 0;
}
