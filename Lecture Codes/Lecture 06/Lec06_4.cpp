#include <iostream>

using namespace std;

struct Point2D{	//Point2D lies in first quadrant means x & y are positive
private:
	int x,y;
public:
	Point2D(){					//Non-parameterized constructor
		x=y=0;
	}
	Point2D(int vx, int vy){	//Parameterized constructor 1
		x = vx;
		y = vy;
	}
	Point2D(int v){				//Parameterized constructor 2
		x = v;
		y = v;
	}
	void set(int vx, int vy){
		setX(vx);	setY(vy);
	}
	void setX(int vx){
		if (vx<0)	x = 0;
		else		x = vx;
	}
	void setY(int vy){
		if (vy<0)	y = 0;
		else		y = vy;
	}
	int getX() const{
		return x;
	}
	int getY() const{
		return y;
	}
};

int main(){
	Point2D p1(3,5);
	cout << "X:" << p1.getX() << ",Y:" << p1.getY() << '\n';//only reading value
	Point2D p2;
	cout << "X:" << p2.getX() << ",Y:" << p2.getY() << '\n';//only reading value
	return 0;
}
