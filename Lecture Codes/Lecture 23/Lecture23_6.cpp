#include <iostream>

using namespace std;

class Singleton{
	Singleton(Singleton &t){}	//Copy constructor in private
	Singleton(){	count++;	}				//Constructor in private
	static Singleton *singleton;//static class member
	static int count;
public:
	void f1(){	cout << "This is a member function\n";	}
	static Singleton* createObject(){	//static member function
		if (singleton==NULL)	singleton = new Singleton;
		return singleton;
	}
	static int getCount(){	return count;	}
};
Singleton* Singleton::singleton=NULL;
int Singleton::count=0;

int main(){
	Singleton *s =	Singleton::createObject();
	s->f1();
	Singleton *s1 =	Singleton::createObject();
	cout << "Count of objects:"	<< Singleton::getCount() << '\n';
	return 0;
}
