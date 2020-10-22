#include <iostream>

using namespace std;

class Rope{
	int feet;
	int inches;
	void normalize(){
		if (inches>=12){
			feet++;
			inches%=12;
		}
	}		
public:
	Rope(int feet=1, int inches=0){
		if (feet==0 && inches==0)
			feet = 1;
		this->feet = feet;
		this->inches = inches;
	}
	int getFeet() const{
		return feet;
	}
	int getInches() const{
		return inches;
	}
	Rope operator+(const Rope &r){
		Rope newRope;
		newRope.feet = feet + r.feet;
		newRope.inches = inches + r.inches;
		newRope.normalize();	
		return newRope;
	}
	Rope& operator++(){
		inches++;
		normalize();
		return *this;
	}
	void show() const{
		cout << "Rope is " << feet << " feet ";
		if (inches > 0)
			cout << inches << " inches ";
		cout << "long\n";
	}
};

int main(){
	Rope r1, r2(3,5);
	r1.show();
	r2.show();
	Rope r3 = ++r1+r2;
	r1.show();
	r3.show();
	return 0;
}

