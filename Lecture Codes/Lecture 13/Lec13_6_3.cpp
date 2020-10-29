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

//Meta -data to add information about file
//Save count of total objects at start of the file
//First of all read count and then take dynamic array and read data according to count

int main(){
	//File 1 is opened for output
	ofstream file1("Rational.txt", ios::app);//File opened for writing in append mode means
											//next output will be added
	RationalNumber r1(4,9);
	file1 << r1 ;
	file1.close();
	//File 2 is opened for input
	ifstream file2("Rational.txt");
	RationalNumber r2;
	for (int i=0;i<6;i++){
		file2 >> r2;
		cout << r2;
	}
	file2.close();
	return 0;
}

	
