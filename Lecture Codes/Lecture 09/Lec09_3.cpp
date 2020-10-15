#include <iostream>
#include <ctime>

using namespace std;

//Static Members: static data members, static member functions
//Instance is a synonym for object
//static members are class members, whereas non-static members are instance member
//Instance data members have separate copy for each instance
//Class data members have single copy for any number of objects
//Static member function is also class function, can access only static members
//Static member function can be called with class name using :: scope resolution operator

/*
static members 							& non-static members
------------------						------------------------
class members							 instance members
exist without creation of object		exist with the creation of object
class data member has only one copy		instance data member has copy for each instance
*/

class ABC{
	const int WIDTH, HEIGHT;
	int x, y;	
	static int count;//shows number of objects
public:
	ABC ():	WIDTH(100), HEIGHT(200){
		x = y = 0;
		count++;
	}
	ABC (int width, int height):	WIDTH(width), HEIGHT(height){
		x = y = 0;
		count++;
	}
	ABC (int width, int height, int x, int y):	WIDTH(width), HEIGHT(height){
		this->x = x;
		this->y = y;
		count++;
	}
	int getWIDTH() const{
		return WIDTH;
	}	
	int getHEIGHT() const{
		return HEIGHT;
	}	
	int getX() const{
		return x;
	}	
	int getY() const{
		return y;
	}	
	~ABC(){
		count--;
	}
	static int getCount(){
		return count;
	}
};
//Static member initalization
int ABC::count=0;


int main(){
	cout << "Total number of objects: " << ABC::getCount() << '\n';
	ABC abc1(30, 70);
	cout << "Total number of objects: " << ABC::getCount() << '\n';
	ABC abc2(50, 100, 10, 20);
	cout << "Total number of objects: " << ABC::getCount() << '\n';
	return 0;
}
