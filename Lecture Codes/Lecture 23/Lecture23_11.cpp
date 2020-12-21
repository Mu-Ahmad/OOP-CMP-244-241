#include <iostream>

using namespace std;

class ThreeObjectsOnly{
	ThreeObjectsOnly(ThreeObjectsOnly &t){}	//Copy constructor in private
	ThreeObjectsOnly(){	count++;	}				//Constructor in private
	static int count;
public:
	void f1(){	cout << "This is a member function\n";	}
	static ThreeObjectsOnly* createObject(){	//static member function
		if (count<3)	return new ThreeObjectsOnly;
		else return NULL;
	}
	static int getCount(){	return count;	}
	~ThreeObjectsOnly(){
		count--;
	}
};
int ThreeObjectsOnly::count=0;

int main(){
	ThreeObjectsOnly *object1 =	ThreeObjectsOnly::createObject();
	if (object1==NULL)		cout << "Object not created\n";
	cout << "Count of objects:"	<< ThreeObjectsOnly::getCount() << '\n';
	ThreeObjectsOnly *object2 =	ThreeObjectsOnly::createObject();
	if (object2==NULL)		cout << "Object not created\n";
	cout << "Count of objects:"	<< ThreeObjectsOnly::getCount() << '\n';
	ThreeObjectsOnly *object3 =	ThreeObjectsOnly::createObject();
	if (object3==NULL)		cout << "Object not created\n";
	cout << "Count of objects:"	<< ThreeObjectsOnly::getCount() << '\n';
	ThreeObjectsOnly *object4 =	ThreeObjectsOnly::createObject();
	if (object4==NULL)		cout << "Object not created\n";
	cout << "Count of objects:"	<< ThreeObjectsOnly::getCount() << '\n';
	delete object2;
	cout << "Count of objects:"	<< ThreeObjectsOnly::getCount() << '\n';
	object4 =	ThreeObjectsOnly::createObject();
	if (object4==NULL)		cout << "Object not created\n";
	cout << "Count of objects:"	<< ThreeObjectsOnly::getCount() << '\n';
	return 0;
}
