#include <iostream>

using namespace std;

class Matrix {
private:
	int rows, cols;
	int **array;
public:
	//Constructor
	Matrix(int r, int c) : rows(r), cols(c) {
		array = new int*[rows];
		while (r--)
			array[r] = new int[cols];
	}
	//Operations
	void readValues() {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				cin >> array[i][j];
	}

	void printMatrix() { //Operation 7
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				cout << array[i][j] << ' ';
			cout << '\n';
		}
	}

	void processRow(int j, int k, int l) {
		for (int i = 0; i < cols; i++)
			array[k - 1][i] += l * (array[j - 1][i]);
	}

	void processCol(int j, int k, int l) {
		for (int i = 0; i < rows; i++)
			array[i][k - 1] += l * (array[i][j - 1]);
	}
//Destructor
	~Matrix() {
		for (int i = 0; i < rows; i++)
			delete[] array[i];
		delete array;
	}
};

int main() {
	// freopen("input.txt", "r", stdin);
	int rowSize, colSize, operations, temp, var1, var2;
	cin >> rowSize >> colSize;
	Matrix matrix(rowSize, colSize);
	matrix.readValues();
	cin >> operations;
	while (operations--) {
		cin >> temp;
		switch (temp) {
		case 1:
			cin >> var1 >> var2;
			matrix.processRow(var1, var1, var2 - 1);
			break;
		case 2:
			cin >> var1 >> var2;
			matrix.processCol(var1, var1, var2 - 1);
			break;
		case 3:
			cin >> var1 >> var2;
			matrix.processRow(var1, var2, 1);
			break;
		case 4:
			cin >> var1 >> var2;
			matrix.processCol(var1, var2, 1);
			break;
		case 5:
			cin >> var1 >> var2;
			matrix.processRow(var1, var2, -1);
			break;
		case 6:
			cin >> var1 >> var2;
			matrix.processCol(var1, var2, -1);
			break;
		case 7:
			matrix.printMatrix();
			break;
		}
	}

}