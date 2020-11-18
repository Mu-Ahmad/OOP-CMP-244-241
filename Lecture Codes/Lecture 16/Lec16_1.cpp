#include <iostream>

using namespace std;

class List{
	int *data;
	const int SIZE;
public:
	List(int=10);
	void setValuesRandomly();
	void show() const;
	~List(){	delete []data;	}
};

//Name of the class followed by double colon (scope resolution operator)
//Default value is not required now, but it is usable as written in declaration
List::List(int s): SIZE(s){
	data = new int[SIZE];
	setValuesRandomly();
}

//Function return type will come first, followed by class name, followed by scope resuolution operator,
//followed by function name
void List::setValuesRandomly(){
	for (int i=0;i<SIZE;i++)
		data[i] = rand() % 100 ;
}
void List::show() const{
	for (int i=0;i<SIZE;i++)
		cout << data[i] << ' ';
	cout << '\n';
}
int main(){
	List list1(5);
	list1.show();
	List list2;
	list2.show();
	return 0;
}
