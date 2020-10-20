#include <iostream>

using namespace std;

class Point2D{
	int x,y;
public:
	Point2D(int x=0, int y=0){
		set(x, y);
	}
	void set(int x=0, int y=0){
		this->x = x;
		this->y = y;
	}
	void show() const{
		cout << "X:" << x << " ,Y:" << y << '\n';
	}
	Point2D operator + (const Point2D &p){
		Point2D newPoint;
		newPoint.x = x + p.x;
		newPoint.y = y + p.y;
		return newPoint;
	}
	void operator - (const Point2D &p){
		Point2D newPoint;
		newPoint.x = x - p.x;
		newPoint.y = y - p.y;
		//newPoint.show();
	}
	/*Point2D operator - (const Point2D &p){
		Point2D newPoint;
		newPoint.x = x - p.x;
		newPoint.y = y - p.y;
		return newPoint;
	}*/
};
	

int main(){
	Point2D p1(3,5), p2(4,7), p3(1,3);
	p2 - p1;
	p1 - p2;
	//(p1 - p2 - p3).show();
	return 0;
}
