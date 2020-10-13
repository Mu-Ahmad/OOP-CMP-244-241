#include <iostream>

using namespace std;

class Point2D{
	int x, y;
public:
	Point2D(int vx, int vy){
		x = vx, y=vy; 	
		cout << "Object created\n"; 
	}
	Point2D (const Point2D &p){
		cout << "Object created using copy constructor\n"; 	
		x = p.x;
		y = p.y;	
	}
	void show() const{
		 cout << "X:" << x << " Y:" << y << '\n';
	}
};
int main(){
	Point2D p1(3,5);
	Point2D p2 = p1;
	p2.show();
	return 0;
}
