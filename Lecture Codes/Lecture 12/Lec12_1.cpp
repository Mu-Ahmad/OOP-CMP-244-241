#include <iostream>

using namespace std;

class Test{

public:
	Test()			{	cout << "Non parameterized constructor\n";	}
	Test(int x)		{	cout << "Parameterized constructor\n";	}
	Test(Test &t)	{	cout << "Copy constructor\n";	}
	~Test()			{	cout << "Destructor\n";			}
	void test(Test t){
		cout << "Inside test function, going to terminate test function\n";
	}
};


int main(){
	Test t1;
	Test t2 = t1;
	Test t3(t1);
	cout << "****************\n";
	t1.test(t2);
	cout << "Main Function is going to end\n";
	return 0;
}

	
