#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Printer{
public:
	virtual void print()=0;
	virtual ~Printer(){	cout << "Printer Destructor Called\n";	}
};
class LaserPrinter:public Printer{
public:
	void print(){	cout << "Do laser printing\n";	}
	~LaserPrinter(){	cout << "Laser Printer Destructor Called\n";	}
};
class InkjetPrinter:public Printer{
public:
	void print(){	cout << "Do inkjet printing\n";	}
	~InkjetPrinter(){	cout << "Inkjet Printer Destructor Called\n";	}
};
class DotMatrixPrinter:public Printer{
public:
	void print(){	cout << "Do dot matrix printing\n";	}
	~DotMatrixPrinter(){	cout << "DotMatrix Printer Destructor Called\n";	}
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
		delete printer;
	}
	return 0;
}
