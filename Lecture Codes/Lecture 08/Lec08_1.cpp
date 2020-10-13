#include <iostream>

using namespace std;
class Matrix{
	int rows, cols, **e;
public:
	Matrix (int r=3, int c=3){//default value of parameters
		rows = r , cols = c;
		e = new int* [rows];
		for (int i=0;i<rows;i++)
			e [i] = new int [cols];
		initRandom();
	}
	Matrix (){}
	void initRandom(){
		int i, j;
		for (i=0;i<rows;i++)
			for (j=0;j<cols;j++)
				e[i][j] = rand() % 10;
	}
	void show() const{
		int i, j;
		for (i=0;i<rows;i++){
			for (j=0;j<cols;j++)
				cout << e[i][j] << ' ';
			cout << '\n';
		}
	}
};
		

int main(){
	Matrix m1, m2(4), m3(5,6);
	m1.show();
	cout << "-------------------\n";
	m2.show();
	cout << "-------------------\n";
	m3.show();
	return 0;
}
