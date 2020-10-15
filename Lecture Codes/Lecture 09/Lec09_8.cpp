#include <iostream>
#include <ctime>

using namespace std;
/*
	Static array of objects
	First of all constructor will be called for all objects
	Secondly, you have to take care of constructor calling

*/

class Point2D{
	int x, y;
public:
	Point2D(int x, int y){
		this->x = x;	this->y = y;
	}
	void show() const{
		cout << '(' << x << ',' << y << ")\n";
	}
};

int main(){
	Point2D points[10];
	return 0;
}
