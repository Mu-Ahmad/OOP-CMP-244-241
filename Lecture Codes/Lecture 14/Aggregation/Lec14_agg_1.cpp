#include <iostream>
#include <fstream>

using namespace std;

class Point2D{
	int x, y;
public:
	Point2D(int x=0, int y=0){
		this->x = x;
		this->y = y;
	}
	friend ostream& operator << (ostream &, const Point2D &);
};
ostream& operator << (ostream &output, const Point2D &p){
	output << p.x << ',' << p.y << '\n';
	return output;
}
class Triangle{
	Point2D p1, p2, p3;
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3): p1(x1, y1), p2(x2, y2), p3(x3, y3){
		//Constructor with empty body
	}
	friend ostream& operator << (ostream &, const Triangle &);
};
ostream& operator << (ostream &out, const Triangle &t){
	out << "Triangle:\n" <<"Point 1: "<< t.p1 <<"Point 2: "<< t.p2 <<"Point 3: "<< t.p3 << "--------\n";
	return out;
}
int main(){
	Triangle t(2,5,8,7,5,4);
	cout << t;
	return 0;
}
