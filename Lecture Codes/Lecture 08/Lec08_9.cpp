#include <iostream>

using namespace std;
class Matrix {
	int rows, cols, **e;//Data Members
	void createCopy(const Matrix &m) {
		int i, j;
		rows = m.rows , cols = m.cols;
		e = new int* [rows];
		for ( i = 0; i < rows; i++) {
			e [i] = new int [cols];
			for (j = 0; j < cols; j++)
				e[i][j] = m.e[i][j];
		}
	}
	void freeMemory() {
		//free allocated memory because object is already existing
		for (int i = 0; i < rows; i++)
			delete []e[i];
		delete []e;
	}
public:
	Matrix (int rows = 3, int cols = 3) { //default value of parameters
		this->rows = rows , this->cols = cols;
		e = new int* [rows];
		for (int i = 0; i < rows; i++)
			e [i] = new int [cols];
		initRandom();
	}
	Matrix (const Matrix &m) {
		createCopy(m);
	}
	Matrix operator = (const Matrix &m) {
		freeMemory();
		createCopy(m);
		return *this;//To return current object
	}
	void initRandom() {
		int i, j;
		for (i = 0; i < rows; i++)
			for (j = 0; j < cols; j++)
				e[i][j] = rand() % 10;
	}
	void setValue(int i, int j, int newValue) {
		if (i < rows && j < cols)
			e[i][j] = newValue;
	}
	void show() const {
		int i, j;
		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++)
				cout << e[i][j] << ' ';
			cout << '\n';
		}
	}
	~Matrix() {
		freeMemory();
	}
};

int main() {
	Matrix m1;
	m1.show();
	cout << "-------------------\n";
	Matrix m2, m3;
	m2.show();
	cout << "-------------------\n";
	m3 = m2 = m1;
	m2.show();
	cout << "-------------------\n";
	m3.show();
	return 0;
}
