#include <iostream>

using namespace std;

class Singleton{
	Singleton(Singleton &t){}	//Copy constructor in private
	Singleton(){}				//Constructor in private
	static Singleton *singleton;//static class member
public:
	void f1(){	cout << "This is a member function\n";	}
	static Singleton* createObject(){	//static member function
		if (singleton==NULL)	singleton = new Singleton;
		return singleton;
	}
};
Singleton* Singleton::singleton=NULL;

int main(){
	Singleton *s =	Singleton::createObject();
	s->f1();
	return 0;
}
