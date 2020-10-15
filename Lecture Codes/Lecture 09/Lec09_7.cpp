#include <iostream>
#include <ctime>

using namespace std;
/*
	Dynamic Objects - created on heap using new operator
	Dynamic objects can be created when they are required, therefore, they will not occupy
	the space without their useage. Dyanmic objects can be deleted soon after their usage, 
	again saving memory.

*/

class Point2D{
	int x, y;
public:
	Point2D(int x, int y){
		this->x = x;	this->y = y;
	}
	~Point2D(){
		cout << '(' << x << ',' << y << ") is terminating\n";
	}
	void show() const{
		cout << '(' << x << ',' << y << ")\n";
	}
};

int main(){
	Point2D *p1, *p2;
	p1 = new Point2D(3, 4);
	p2 = new Point2D(7, 5);
	delete p1;
	cout << "P1 is deleted, whereas P2 still exist\n";
	p2->show();
	cout << "Now deleting P2\n";
	delete p2;
	return 0;
}
