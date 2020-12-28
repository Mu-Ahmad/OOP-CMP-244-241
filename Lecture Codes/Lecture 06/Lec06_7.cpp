#include <iostream>

using namespace std;

class Rope {	//Rope has 2 data members. Feet & inches with positive values and inches<12
	int feet, inches;
public:
	Rope() {					//Non-parameterized constructor
		feet = 1;
		inches = 0;
	}
	Rope(int feet, int inches) {
		setFeet(feet);
		setInches(inches);
	}
	void set(int feet, int inches) {
		setFeet(feet);	setInches(inches);
	}
	void setFeet(int f) {
		if (f > 0)			feet = f;
		else				feet = 1;
	}
	void setInches(int i) {
		if (i >= 0 && i < 12)	inches = i;
		else if (i < 0)		inches = 0;
		else				{ feet += i / 12;	inches = i % 12 ; }
	}
	int getFeet() const {
		return feet;
	}
	int getInches() const {
		return inches;
	}
	void show() const {
		cout << feet << " Feet ";
		if (inches > 0)
			cout << inches << " Inches\n";
		else
			cout << '\n';
	}
	~Rope() {
		cout << "Destructor Called \n";
	}
};

int main() {
	Rope r1(3, 15), r2(2, 5);
	r1.show();
	r2.show();
	return 0;
}
