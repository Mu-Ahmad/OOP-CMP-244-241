#include<bits/stdc++.h>
using namespace std;

#define deb(x)                cout<< #x << ' ' << x << endl
#define deb2(x, y)          cout<< #x << ' ' << x <<' '<< #y << ' ' << y << endl
#define deb3(x, y, z)       cout<< #x << ' ' << x << ' '<<#y << ' ' << y << ' ' << #z << ' ' << z << endl

int main() {
	// freopen("input.txt", "r", stdin);
	int rows, cols; cin >> rows >> cols;
	int matrix[rows][cols], array[rows * cols];
	int pos1 = 0, pos2 = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin >> matrix[i][j];

	for (int i = 0; i < rows * cols; i++) {
		int row_n = floor(i / cols * 1.0), col_n = i % cols;
		array[i] = matrix[row_n][col_n];
	}

	sort(array, array + (cols * rows));
	// for (int i = 0; i < rows * cols; i++)
	//     cout << array[i] << ' ';
	int k = 1;
	bool found = false;
	for (int i = 0; i < rows * cols; i += k) {
		k = 1;
		for (int j = 0; j < rows * cols; j++) {
			int row_n = j / cols, col_n = j % cols;
			if (found) {
				if (matrix[row_n][col_n] == array[i + k])
					k++;
				else
					break;
			}

			if (matrix[row_n][col_n] == array[i]) {
				found = true;
				pos1 = row_n;
				pos2 = col_n;
			}
		}
		// deb(array[i]);
		cout << pos1 + 1 << ' ' << pos2 + 1 << ' ' << k << '\n';
		found = false;
	}

	return 0;
}