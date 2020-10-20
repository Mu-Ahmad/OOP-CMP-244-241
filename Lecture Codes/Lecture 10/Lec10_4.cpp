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
};
	

int main(){
	Point2D p1(3,5), p2(4,7);
	p1 + p2;
	return 0;
}
