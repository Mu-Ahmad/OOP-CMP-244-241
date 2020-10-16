Lec09_9.cpp
Yesterday
Thu 10:41 AM

Abdul Mateen uploaded an item
C++
Lec09_9.cpp
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
	Point2D(int x=0, int y=0){
		this->x = x;	this->y = y;
	}
	void show() const{
		cout << '(' << x << ',' << y << ")\n";
	}
};

int main(){
	Point2D points[10];//By default non-parameterized constructor is called
	for (int i=0;i<10;i++)
		points[i].show();
	return 0;
}
