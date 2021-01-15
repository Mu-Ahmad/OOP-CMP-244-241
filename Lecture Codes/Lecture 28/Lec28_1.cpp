#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

class A{
public:
	void fa(){	cout << "Function of A\n";	}
};
class B:public A{
public:
	void fb(){	cout << "Function of B\n";	}
};
class C:public B{
public:
	void fc(){	cout << "Function of C\n";	}
};
int main() {
	C *cPtr = new C;
	cPtr->fa();
	cPtr->fb();
	cPtr->fc();
	return 0;
}
