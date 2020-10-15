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
	Point2D(){
		cout << "I am created, yahoo\n";
	}
	~Point2D(){
		cout << "Good bye, I am dying\n";
	}
};

int main(){
	Point2D *p;
	cout << "So far no object is created, now we will create an object\n\n";
	p = new Point2D;
	cout << "Some fazool messages\n\n";
	delete p;
	cout << "Object  is deleted, program is still live\n";
	cout << "Now program is going to terminate\n";
	return 0;
}
