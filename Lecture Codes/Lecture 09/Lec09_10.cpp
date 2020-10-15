#include <iostream>
#include <ctime>

using namespace std;
/*
	Static array of objects
	First of all constructor will be called for all objects
	Secondly, you have to take care of constructor calling

	While creating array of objects, you have only two options, either call non-parameterized
	constructor or call specific constructors for individual elements at the time of creation
*/

class Point2D{
	int x, y;
public:
	Point2D(int x=0, int y=0){
		this->x = x;	this->y = y;
	}
	void show() const{
		cout << '(' << x << ',' << y << ")\n";
	}
};

int main(){
	Point2D points[5]={Point2D(3), Point2D(4,2), Point2D(6,1)};
	for (int i=0;i<5;i++)
		points[i].show();
	return 0;
}
