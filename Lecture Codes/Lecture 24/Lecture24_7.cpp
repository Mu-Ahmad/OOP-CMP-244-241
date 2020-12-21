#include <iostream>

using namespace std;

class Point{
	int x,y;
public:
	Point (int x=0, int y=0){	this ->x = x;	this ->y = y;		}
	friend ostream& operator << (ostream &out, const Point &point){
		out << "X: " << point.x << " , Y: " << point.y << "   ";
		return out;
	}
};
template <class MyType>
class MyList{
	MyType *data;
	int cSize;
	int size;
	MyList& copy(MyList &list){
		size = list.size;
		cSize = list.cSize;
		data = new MyType[size];
		for (int i=0;i<cSize;i++)
			data[i] = list.data[i];
		return *this;
	}
public:
	MyList(int size = 10 ){
		this->size = size;
		cSize = 0;
		data = new MyType[size];
	}
	void add(MyType element){
		if (cSize<size)
			data[cSize++] =  element;
	}
	MyList (const MyList &list){	copy(list);	}
	MyList& operator = (const MyList &list){	
		delete []data;
		return copy(list);	
	}
	~MyList(){	delete []data;	}
	friend ostream& operator << (ostream &out, const MyList &list){
		for (int i=0;i<list.cSize;i++)
			out << list.data[i] << ' ';
		out << '\n';
		return out;
	}	
};
int main(){
	MyList <Point> list2;
	Point p1(2,5), p2(3,7), p3(4,2);
	list2.add(p1);	list2.add(p2);	list2.add(p3);
	cout << "List2: " << list2 ;


	return 0;
}

