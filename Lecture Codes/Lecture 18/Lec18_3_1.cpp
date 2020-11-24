#include <iostream>

using namespace std;

class Point2D{
	int x, y;
public:
	Point2D(int x=0, int y=0){	this->x=x;	this->y=y;	} 
	void show()	{	cout << "X:" << x << ", Y:" << y ;	} 
};
class Point3D:public Point2D{
	int z;
public:
	Point3D(int x=0, int y=0, int z=0):Point2D(x, y){	this->z = z;	} 
	void show() { Point2D::show();	cout << ", Z:" << z << '\n';		}
};

int main(){
	Point3D p1(3,5,1);
	p1.show();

	Point2D p2(4,7);
	p2.show();
	cout << '\n';
	return 0;
}
