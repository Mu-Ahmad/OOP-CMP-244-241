#include <iostream>
#include <iomanip>

using namespace std;

struct Matrix{
	int **data, rows, columns;
	void set(const int ROWS, const int COLUMNS){
		rows = ROWS;
		columns = COLUMNS;
		data = new int*[ROWS];//memory of 1d pointers
		for (int i=0;i<ROWS;i++)
			data[i] = new int [COLUMNS];
	}
	void initRandom(){
		int i,j;
		for (i=0;i<rows;i++)
			for (j=0;j<columns;j++)
				data[i][j] = rand()%9 + 1;
	}
	void show(){
		int i,j;
		for (i=0;i<rows;i++){
			for (j=0;j<columns;j++)
				cout << setw(3) << data[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
	Matrix add(Matrix &m){
		Matrix newMatrix;
		newMatrix.set(rows, columns);
		int i,j;
		for (i=0;i<rows;i++)
			for (j=0;j<columns;j++)
				newMatrix.data[i][j] = data[i][j] + m.data[i][j];
		return newMatrix;
	}
	void free(){
		for (int i=0;i<rows;i++)
			delete []data[i];
		delete data;
	}
};

int main(){
	srand(time(0));
	Matrix m1, m2;
	m1.set(3,5);
	m1.initRandom();
	m1.show();
	m2.set(3,5);
	m2.initRandom();
	m2.show();
	Matrix addMatrix;
	addMatrix = m1.add(m2);
	addMatrix.show();

	m1.free();
	m2.free();
	addMatrix.free();
	return 0;
}
