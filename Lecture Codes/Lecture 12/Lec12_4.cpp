#include <iostream>

using namespace std;

class Test{

public:
	Test()			{	cout << "Non parameterized constructor\n";	}
	Test(int x)		{	cout << "Parameterized constructor\n";	}
	Test(Test &t)	{	cout << "Copy constructor\n";	}
	void operator = ( const Test &t)	{	cout << "Assignment operator\n";	}
	~Test()			{	cout << "Destructor\n";			}
	Test operator + (const Test &t){
		Test newObject;
		return newObject;
	}
};

int main(){
	Test t1;
	Test t2 = t1;
	t2 = t1;
	Test t3;
	cout << "********** Calling + operator *********\n";
	t3 = t1 + t2;
	cout << "Main Function is going to end\n";
	return 0;
}

	
