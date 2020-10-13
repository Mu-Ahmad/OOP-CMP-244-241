#include <iostream>

using namespace std;

class Point2D{	//Point lies in first quadrant, means both x & y are positive
	int x, y;
public:
	void set(int vx, int vy){
		if (vx<0)	x = 0;
		else		x = vx;
		if (vy<0)	y = 0;
		else		y = vy;
	}
	void showPoint() const{   	//This function is not allowed to change value of data member
		cout << "X:" << x << ", Y:" << y << '\n' ;
	}
};
int main(){
	Point2D p1, p2;
	p1.set(3,5);
	p2.set(-2,4);
	p1.showPoint();
	p2.showPoint();
	return 0;
}


