#include <iostream>

using namespace std;

class Test{

public:
	Test()				{	cout << "Non parameterized constructor\n";	}
	Test(const Test &t)	{	cout << "Copy constructor\n";	}
	void operator = ( const Test &t)	{	cout << "Assignment operator with constant parameter\n";	}
	void operator = ( Test &t)			{	cout << "Assignment operator without constant parameter\n";	}
	Test operator + (const Test &t){
		Test newObject;
		return newObject;
	}
	void show(){	cout << "Show Function is Called\n";	}
		
};
ostream& operator << (ostream &output, const Test &t){
	output << "Ostream operator called\n";
	return output;
}

//Annonymous Object is by default read only and purpose of const is to make/ keep object read only

int main(){
	Test t1, t2;
	cout << t1;
	cout << t1 + t2 ;

	return 0;
}

	
