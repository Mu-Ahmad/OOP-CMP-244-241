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
class XYZ{
public:
	void fxyz(){	cout << "Function of XYZ\n";	}
};
int main() {
	B *bPtr = new C;
	bPtr->fa();
	bPtr->fb();
	
	//C++ type casting     
	C *cPtr = static_cast <C*> (bPtr);
	cPtr->fc();
	return 0;
}
