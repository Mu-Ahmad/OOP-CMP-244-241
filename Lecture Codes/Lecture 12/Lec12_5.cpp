#include <iostream>

using namespace std;

class Test{

public:
	Test()			{	cout << "Non parameterized constructor\n";	}
	Test(int x)		{	cout << "Parameterized constructor\n";	}
	Test(Test &t)	{	cout << "Copy constructor\n";	}
	void operator = ( const Test &t)	{	cout << "Assignment operator with constant parameter\n";	}
	void operator = ( Test &t)			{	cout << "Assignment operator without constant parameter\n";	}
	~Test()			{	cout << "Destructor\n";			}
	Test operator + (const Test &t){
		Test newObject;
		return newObject;
	}
	void show(){	cout << "Show Function is Called\n";	}
		
};
//Annonymous Object is by default read only and purpose of const is to make/ keep object read only

int main(){
	Test t1;
	Test t2 = t1;
	t2 = t1;//Assignment operator without constant parameter
	Test t3;
	cout << "********** Calling + operator *********\n";
	//(t1 + t2).show();
	t3 = t1 + t2;
	cout << "Main Function is going to end\n";
	return 0;
}

	
