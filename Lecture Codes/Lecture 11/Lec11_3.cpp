#include <iostream>

using namespace std;

class Rope{
	int feet;
	int inches;
public:
	void normalize(){
		if (inches>=12){
			feet++;
			inches%=12;
		}
	}		
	Rope(int feet=1, int inches=0){
		if (feet==0 && inches==0)
			feet = 1;
		this->feet = feet;
		this->inches = inches;
	}
	void setFeet(int feet){
		this->feet = feet;
	}
	void setInches(int inches){
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
	//Pre increment operator
	Rope& operator++(){
		inches++;
		normalize();
		return *this;
	}
	//Post increment operator
	Rope operator++(int){
		Rope newRope = *this;//Created a copy using default copy constructed
		inches++;
		normalize();
		return newRope;//Return object with previous values
	}
	void show() const{
		cout << "Rope is " << feet << " feet ";
		if (inches > 0)
			cout << inches << " inches ";
		cout << "long\n";
	}
};

//Global function
//There is no caller object of global function, therefore all objects are passed
//Multiplying with k means rope is increasing k times
void operator * (Rope &r, int k){
	r.setFeet (r.getFeet() * k);
	r.setInches (r.getInches() * k);
	r.normalize();
}


int main(){
	Rope r2(3,5);
	r2.show();
	r2 * 3;
	r2.show();
	return 0;
}

