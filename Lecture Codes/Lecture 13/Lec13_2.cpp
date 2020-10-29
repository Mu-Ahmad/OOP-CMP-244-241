#include <iostream>

using namespace std;

class RationalNumber{
	int x, y;
public:
	RationalNumber(int x=0, int y=1){	//Both parameterized and Non-parameterized constructor
		set(x, y);
	}
	void set(int x=0, int y=1){	
		if (y==0)	y = 1;
		if ((x < 0 && y < 0) || (x >=0 && y < 0)){	x=-x;	y=-y;	} 
		this->x = x;			this->y = y;
	}
	int getX() const {	return x;	}
	int getY() const {	return y;	}
};
ostream& operator << (ostream &output, const RationalNumber &r){
	int x=r.getX(), y=r.getY();
	if (x==0)	cout << 0 << '\n';	
	else		cout << x << '/' << y << '\n';
	return output;
}

int main(){
	RationalNumber r1, r2(3,-4), r3(-4, -5), r4(-5,4);
	cout << r1 << r2 << r3 << r4;
	return 0;
}

	
