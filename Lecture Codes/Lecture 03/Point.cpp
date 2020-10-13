#include <iostream>

using namespace std;

struct Point{
	int x, y;
};

struct Point reverse(Point &p1){
	Point p2;
	p2.x = - p1.x;
	p2.y = - p1.y;
	return p2;
}

int main(){
	struct Point p1, p2;
	p1.x=3, p1.y=-5;
	p2.x=4, p2.y=1;
	cout<<p1.x<<", "<<p1.y<<'\n';
	cout<<p2.x<<", "<<p2.y<<'\n';
	
	Point p3 = reverse(p1);
	cout<<p3.x<<", "<<p3.y<<'\n';	
	return 0;
}
