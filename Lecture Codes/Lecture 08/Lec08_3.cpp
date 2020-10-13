#include <iostream>

using namespace std;
class Matrix{
	int rows, cols, **e;//Data Members
public:
	Matrix (int r=3, int c=3){//default value of parameters
		rows = r , cols = c;
		e = new int* [rows];
		for (int i=0;i<rows;i++)
			e [i] = new int [cols];
		initRandom();
	}
	Matrix (const Matrix &m){
		int i, j;
		rows = m.rows , cols = m.cols;
		e = new int* [rows];
		for ( i=0;i<rows;i++){
			e [i] = new int [cols];
			for (j=0;j<cols;j++)
				e[i][j] = m.e[i][j];
		}
	}
	void initRandom(){
		int i, j;
		for (i=0;i<rows;i++)
			for (j=0;j<cols;j++)
				e[i][j] = rand() % 10;
	}
	void setValue(int i, int j, int newValue){
		if (i<rows && j<cols)
			e[i][j] = newValue;	
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
	Matrix m1;
	m1.show();
	cout << "-------------------\n";
	Matrix m2;
	m2.show();
	cout << "-------------------\n";
	m1.setValue(1,1,20);
	m1.show();
	cout << "-------------------\n";
	m2 = m1;  //Assignment operator is called, which exist in every class by default
				//In case of pointer members, default assignment operator creates shallow copy

	m2.show();
	return 0;
}
