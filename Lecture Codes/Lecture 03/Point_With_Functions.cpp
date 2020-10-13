#include <iostream>

using namespace std;

struct Point{
	int x, y;
	void set(int x1, int y1){
		x=x1, y=y1;
	}
	void show(){
		cout << "X:" << x << ", Y:" << y << '\n';
	}
	Point reverse(){
		Point newP;
		newP.x=-x, newP.y=-y;
		return newP;
	}
};

int main(){
	struct Point p1, p2;
	p1.set(3, -5);
	p2.set(4, 1);
	p1.show();
	p2.show();
	Point p3 = p1.reverse();
	p3.show();
	return 0;
}
