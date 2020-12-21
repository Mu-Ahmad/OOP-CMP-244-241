#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Printer{
public:
	virtual void print()=0;//pure virtual function
	~Printer(){	cout << "Destructor Printer\n";	}
};
class LaserPrinter:public Printer{
public:
	//Function Overrided
	void print(){	cout << "Do laser printing\n";	}
	~LaserPrinter(){	cout << "Destructor LaserPrinter\n";	}
};
class InkjetPrinter:public Printer{
public:
	void print(){	cout << "Do inkjet printing\n";	}
	~InkjetPrinter(){	cout << "Destructor InkjetPrinter\n";	}
};
class DotMatrixPrinter:public Printer{
public:
	void print(){	cout << "Do dot matrix printing\n";	}
	~DotMatrixPrinter(){	cout << "Destructor DotMatrixPrinter\n";	}
};
int main(){
	srand(time(0));
	Printer *printer;
	int value;
	for (int i=0;i<5;i++){
		value = rand() % 3;
		switch(value){
			case 0: printer = new LaserPrinter;		break;
			case 1: printer = new InkjetPrinter;	break;
			case 2: printer = new DotMatrixPrinter;	break;
		}
		printer->print();
		delete printer;
	}
	return 0;
}
