#include <iostream>

using namespace std;

class Point2D{
	int x,y;
public:
	Point2D(int x, int y){
		this->x = x;
		this->y = y;
	}
	void show() const{
		cout << "X:" << x << " ,Y:" << y << '\n';
	}
};
	

int main(){
	Point2D *points = new Point2D[10];
	for (int i=0;i<10;i++)
		points[i].show();
	delete []points;
	return 0;
}
