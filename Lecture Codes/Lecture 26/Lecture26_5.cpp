#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
 
class Point{
	int x, y;
public:
	Point(){	x = rand() % 10; y = rand() % 10;	}
	friend ostream& operator << (ostream &out, const Point &p){
		out << '(' << p.x << ',' << p.y << ')';
		return out;
	}
};
int main() {
    vector<Point> vec; 
    srand(time(0));
    Point p[5];
    int i;
    //Adding 5 point type objects into vector
    for(i = 0; i < 5; i++) 
        vec.push_back(p[i]);
    cout << "\nValues from list: ";
    for(i = 0; i < 5; i++)
        cout << vec[i] << ' ';
    cout << '\n';
    return 0;
}
