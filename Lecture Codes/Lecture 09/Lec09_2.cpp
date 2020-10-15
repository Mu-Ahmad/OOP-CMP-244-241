#include <iostream>
#include <ctime>

using namespace std;

//const data members. Such data members can be initialized once for any individual object.
//Constant data members are initialized before the constructor body


class ABC{
	const int WIDTH, HEIGHT;
	int x, y;	
public:
	ABC ():	WIDTH(100), HEIGHT(200){
		x = y = 0;
	}
	ABC (int width, int height):	WIDTH(width), HEIGHT(height){
		x = y = 0;
	}
	ABC (int width, int height, int x, int y):	WIDTH(width), HEIGHT(height){
		this->x = x;
		this->y = y;
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
};


int main(){
	ABC abc1(30, 70), abc2(50, 100, 10, 20);
	cout << abc1.getWIDTH() << ' ' << abc1.getHEIGHT() << '\n';
	cout << abc2.getWIDTH() << ' ' << abc2.getHEIGHT() << ' ' << abc2.getX() <<
		' ' << abc2.getY()<<'\n';
	return 0;
}
