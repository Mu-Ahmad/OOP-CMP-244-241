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
	void setRandomValues(){
		x = rand()%10;
		y = rand()%10;
	}
	
	void show() const{
		cout << '(' << x << ',' << y << ")\t";
	}
};

int main(){
	Point2D points[100];
	int i;
	for (i=0;i<100;i++)
		points[i].show();
	cout << "-----------------\n";
	for (i=0;i<100;i++){
		points[i].setRandomValues();	
		points[i].show();
	}
	return 0;
}
