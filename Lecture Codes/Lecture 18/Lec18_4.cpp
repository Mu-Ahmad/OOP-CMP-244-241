#include <iostream>

using namespace std;

class Point2D{
	int x, y;
public:
	Point2D(int x=0, int y=0){	this->x=x;	this->y=y;	} 
	void show()	{	cout << "X:" << x << ", Y:" << y ;	} 
	int getX() const{	return x;	}
	int getY() const{	return y;	}
};
class Point3D:public Point2D{
	int z;
public:
	Point3D(int x=0, int y=0, int z=0):Point2D(x, y){	this->z = z;	} 
	void show() { Point2D::show();	cout << ", Z:" << z << '\n';		}
	int getZ() const{	return z;	}
};

int main(){
	Point3D p(3,5,1);
	//p.show();
	cout << p.getX() << ':' << p.getY() << ':' << p.getZ() << '\n';
	return 0;
}
