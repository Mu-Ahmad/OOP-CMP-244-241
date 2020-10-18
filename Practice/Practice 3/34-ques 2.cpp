#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix {
	private:
		int **matrix, KthRow, KthCol, JthRow, JthCol, Rows, Cols, scalar;
	public:
		Matrix (const int rows, const int cols) {
			int i;
			Rows = rows;
			Cols = cols;
			matrix = new int* [Rows];
			for (i = 0 ; i < Rows ; i++) {
				matrix[i] = new int[Cols];
			}
		}
		void read() {
			int i, j;
			for (i = 0 ; i < Rows ; i++) {
        		for (j = 0 ; j < Cols ; j++) {
            		cin >> matrix[i][j];
        		}	
			}
    	}
		void Kth_row_with_scalar () {
			int i, j;
			cout << "Enter which Row to multiply scalar to (Row, scalar) : \n";
			cin >> KthRow >> scalar;
            for (i = 0 ; i < Rows ; i++) {
                for (j = 0 ; j < Cols ; j++) {
                    if (i == KthRow-1) {
                        matrix[KthRow-1][j] *= scalar;
                    }
                }
            }
		}
		void Kth_col_with_scalar () {
			int i, j;
			cout << "Enter which Column to multiply scalar to (Column, scalar) : \n";
			cin >> KthCol >> scalar;
            for (i = 0 ; i < Rows ; i++) {
                for (j = 0 ; j < Cols ; j++) {
                    if (j == KthCol-1) {
                        matrix[i][KthCol-1] *= scalar;
                    }
                }
            }
		}
		void Add_JthRow_to_KthRow () {
			int i, j;
			cout << "Enter jth Row to add to kth Row (jth Row, kth Row) : \n";
			cin >> JthRow >> KthRow;
            for (i = 0 ; i < Rows ; i++) {
                for (j = 0 ; j < Cols ; j++) {
                    if (i == KthRow-1) {
                        matrix[KthRow-1][j] += matrix[JthRow-1][j];
                    }
                }
            }
		}
		void Add_JthCol_to_KthCol () {
			int i, j;
			cout << "Enter jth Column to add to kth Column (jth Column, kth Column) : \n";
			cin >> JthCol >> KthCol;
            for (i = 0 ; i < Rows ; i++) {
                for (j = 0 ; j < Cols ; j++) {
                    if (j == KthCol-1) {
                        matrix[i][KthCol-1] += matrix[i][JthCol-1];
                    }
                }
            }
		}
		void Subtract_JthRow_from_KthRow () {
			int i, j;
			cout << "Enter jth Row to subtract from kth Row (jth Row, kth Row) : \n";
			cin >> JthRow >> KthRow;
            for (i = 0 ; i < Rows ; i++) {
                for (j = 0 ; j < Cols ; j++) {
                    if (i == KthRow-1) {
                        matrix[KthRow-1][j] -= matrix[JthRow-1][j];
                    }
                }
            }
		}
		void Subtract_JthCol_from_KthCol () {
			int i, j;
			cout << "Enter jth Column to subtract from kth Column (jth Column, kth Column) : \n";
			cin >> JthCol >> KthCol;
            for (i = 0 ; i < Rows ; i++) {
                for (j = 0 ; j < Cols ; j++) {
                    if (j == KthCol-1) {
                        matrix[i][KthCol-1] -= matrix[i][JthCol-1];
                    }
                }
            }
		}
		void show() {
			int i, j;
			for (i = 0 ; i < Rows ; i++) {
                for (j = 0 ; j < Cols ; j++) {
                    cout << matrix[i][j] << ' ';
            }
                cout << '\n';
                }
                cout << "==================\n";
		}
};

int main() {
    int rows, cols, total_op, curr_op, i, j, a = 1, KthRow, KthCol, JthRow, JthCol, scalar;
    Matrix m(3, 3);
    m.read();
    m.Kth_row_with_scalar();
    m.show();
    m.Kth_col_with_scalar();
    m.show();
    m.Add_JthRow_to_KthRow();
    m.show();
    m.Add_JthCol_to_KthCol();
    m.show();
    m.Subtract_JthRow_from_KthRow();
    m.show();
    m.Subtract_JthCol_from_KthCol();
    m.show();
    return 0;
}

