#include <iostream>
#include <fstream>

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
	if (x==0)	output << 0 << '\n';	
	else		output << x << ' ' << y << '\n';
	return output;
}
istream& operator >> (istream &input, RationalNumber &r){
	int x,y=1;
	input >> x;
	if (x!=0) 		input >> y;
	r.set(x,y);
	return input;
}
int main(){
	//File 1 is opened for output
	ofstream file1("Rational.rat", ios::binary);//File opened for writing in binary mode
	RationalNumber r1[4];
	r1[0].set(3,5);
	r1[1].set(-5,7);
	r1[2].set(4,-3);
	r1[3].set(1,1);
	file1.write ( (char *)r1, sizeof(RationalNumber) * 4);
	file1.close();

	//File 2 is opened for input in binary mode
	RationalNumber r2[4];
	ifstream file2("Rational.rat", ios::binary);
	file2.read  ( (char *)r2, sizeof(RationalNumber) * 4);
	for (int i=0;i<4;i++)
		cout << r2[i] ;
	file2.close();
	return 0;
}

	
