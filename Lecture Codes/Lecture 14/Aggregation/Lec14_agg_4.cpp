#include <iostream>
#include <fstream>

using namespace std;

class Point2D{
	int x, y;
public:
	Point2D(){	//Non parameterized constructor
		x = rand()%10;
		y = rand()%10;
	}
	Point2D(int x, int y){//Parameterized constructor only
		this->x = x;
		this->y = y;
	}
	friend ostream& operator << (ostream &, const Point2D &);
};
ostream& operator << (ostream &output, const Point2D &p){
	output << p.x << ',' << p.y << '\n';
	return output;
}
class Polygon{
	Point2D p[10];
public:
	friend ostream& operator << (ostream &, const Polygon &);
};
ostream& operator << (ostream &out, const Polygon &polygon){
	out << "Polygon:\n";
	for (int i=0;i<10;i++)
		out << "Point " << i+1 << ':' << polygon.p[i] ;
	out << "----------\n";
	return out;
}
int main(){
	Polygon p;
	cout << p;
	return 0;
}
