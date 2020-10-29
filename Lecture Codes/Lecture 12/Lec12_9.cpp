#include <iostream>

using namespace std;

class Test{
	int x;
public:
	Test()			{	cout << "Non parameterized constructor\n";	}
	Test(Test &t)		{	cout << "Copy constructor without const\n";	}
	Test(const Test &t)	{	cout << "Copy constructor with const\n";	}
	void operator = ( const Test &t)	{	cout << "Assignment operator with const\n";	}
	void operator = ( Test &t)			{	cout << "Assignment operator without const\n";	}
	Test operator + (const Test &t){
		Test newObject;
		return newObject;
	}
	Test& operator += (const Test &t){
		return *this;
	}
	~Test(){	cout << "Destructor\n";	}

	void show(){	cout << "Show\n";	}
		
};

int main(){
	Test t1, t2;
	cout << "****** Calling operator + for new object ********\n";
	Test t3 = t1 + t2;
	cout << "****** Calling operator + for existing object ********\n";
	t3 = t1 + t2;
	cout << "****** Calling operator +=  ********\n";
	(t1 += t2).show();
	cout << "****** Calling operator += assigning to new object ********\n";
	t3 = t1 += t2;
	cout << "****** Main function is end ********\n";
	return 0;
}

	
