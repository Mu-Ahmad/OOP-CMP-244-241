#include <iostream>

using namespace std;

class Test{

public:
	Test()			{	cout << "Non parameterized constructor\n";	}
	Test(int x)		{	cout << "Parameterized constructor\n";	}
	Test(Test &t)	{	cout << "Copy constructor\n";	}
	~Test()			{	cout << "Destructor\n";			}
	void test1(Test t){	}
	void test2(Test &t){	}
};


int main(){
	Test t1;
	Test t2 = t1;
	cout << "********Calling Test 1 *************\n";
	t1.test1(t2);
	cout << "********Calling Test 2 *************\n";
	t1.test2(t2);
	cout << "Main Function is going to end\n";
	return 0;
}

	
