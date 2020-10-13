#include <iostream>

using namespace std;

class Point2D{
	int x, y;
public:
	Point2D(int vx, int vy){
		x = vx, y=vy; 	
		cout << "Object created\n"; 
	}
	void set(int vx, int vy){
		x = vx, y=vy; 	
	}
	void show() const{
		 cout << "X:" << x << " Y:" << y << '\n';
	}
};
int main(){
	Point2D p1(3,5);
	p1.set(3, 7);
	Point2D p2 = p1;
	cout << "Point P2:";
	p2.show();
	p1.set(2, 6);
	cout << "Point P1:";
	p1.show();
	cout << "Point P2:";
	p2.show();
	return 0;
}
